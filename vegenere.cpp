#include <iostream>
#include <vector>
#include <algorithm>
#include "vegenere.h"
#include "service_manager.h"

void Vegenere::encrypting() {
    ServiceManager serviceManager;
    text_ = serviceManager.removeSpace(text_);
    int j = 0;
    for (unsigned int i = 0; i < text_.size(); i++) {
        text_[i] = alphabet_[(serviceManager.searchNumInput(i, text_, alphabet_) + serviceManager.searchNumInput(j, key_, alphabet_)) % alphabet_.size()];
        j++;
        if (j >= key_.size()) j = 0;
    }
    std::cout << "\nЗашифрованный текст: " << text_ << std::endl;
}
void Vegenere::decrypting() {
    ServiceManager serviceManager;
    std::vector<double> FREQ_ENGLISH = { 0.0816, 0.0149, 0.0202, 0.0425, 0.1270, 0.0222, 0.0201, 0.0609, 0.0696, 0.0015,
                                        0.0129, 0.0402, 0.0240, 0.0674, 0.0750, 0.0192, 0.0009, 0.0598, 0.0632, 0.0935,
                                        0.0275, 0.0095, 0.0256, 0.0015, 0.0199, 0.0007 };
    int key_length = 2;
    // поиск длины ключа
    for (key_length; key_length < 12; key_length++) {
        if (indexOfCoincidence(key_length, text_) > IOC) break;
    }
    std::cout << "\nДлина ключа: " << key_length << std::endl;

    // поиск букв ключа
    for (int i = 0; i < key_length; i++) {
        std::string text_shift;
        std::vector<double> buffer_diff;
        // разбиваем на группы
        for (unsigned int j = i; j < text_.length(); j += key_length) {
            text_shift.push_back(text_[j]);
        }
        for (unsigned int n = 0; n < alphabet_.size(); n++) {
            // частота группы
            std::vector<double> freqs;
            for (auto& letter : alphabet_) {
                freqs.push_back(std::count(text_shift.begin(), text_shift.end(), letter) * 1.0 / text_shift.size());
            }
            // сравнение с частотами
            double diff = 0;
            for (unsigned int m = 0; m < alphabet_.size(); m++) {
                diff += abs(freqs[m] - FREQ_ENGLISH[m]);
            }
            text_shift = serviceManager.shiftText(text_shift, alphabet_, 1);
            buffer_diff.push_back(diff);
        }
        int index = std::min_element(buffer_diff.begin(), buffer_diff.end()) - buffer_diff.begin();
        key_dec_.push_back(alphabet_[alphabet_.size() - index]);
    }
    std::cout << "\nРасшифрованный ключ: " << key_dec_ << std::endl;
    int a = 0;
    for (unsigned int i = 0; i < text_.size(); i++) {
        text_[i] = alphabet_[(serviceManager.searchNumInput(i, text_, alphabet_) - serviceManager.searchNumInput(a, key_dec_, alphabet_)
            + alphabet_.size()) % alphabet_.size()];
        a++;
        if (a >= key_.size()) a = 0;
    }
    std::cout << "\nРасшифрованный текст: " << text_ << std::endl;
}

// индекс совпадений
double Vegenere::indexOfCoincidence(int shift, std::string input) {
    std::string buffer_text;
    // создаем буффер со сдвигом
    for (unsigned int i = 0; i < input.size(); i++) {
        buffer_text.push_back(input[i]);
        i += shift - 1;
    }
    // подсчет индекса совпадений
    double ioc = 0;
    for (auto& letter : alphabet_) {
        auto n = std::count(buffer_text.begin(), buffer_text.end(), letter);
        ioc += static_cast<double>(n * (n - 1)) / static_cast<double>(buffer_text.size() * (buffer_text.size() - 1));
    }
    return ioc;
}
Vegenere::Vegenere(std::string& key, std::string& text, std::string& alphabet) : key_(key), text_(text), alphabet_(alphabet) {
    encrypting();
    decrypting();
}