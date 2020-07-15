#include <iostream>
#include "gamm.h"
#include "service_manager.h"

void Gamm::encrypting() {
    // сложение по модулю N
    ServiceManager serviceManager;
    int j = 0;
    for (unsigned int i = 0; i < text_.length(); i++) {
        text_[i] = alphabet_[(serviceManager.searchNumInput(i, text_, alphabet_) +
            serviceManager.searchNumInput(j, key_, alphabet_))
            % alphabet_.length()];
        j++;
        if (j >= key_.size()) j = 0;
    }
}
void Gamm::decrypting() {
    ServiceManager serviceManager;
    int j = 0;
    for (unsigned int i = 0; i < text_.length(); i++) {
        text_[i] = alphabet_[(serviceManager.searchNumInput(i, text_, alphabet_) + alphabet_.length()
            - serviceManager.searchNumInput(j, key_, alphabet_))
            % alphabet_.length()];
        j++;
        if (j >= key_.size()) j = 0;
    }
}
Gamm::Gamm(std::string& key, std::string& text, std::string& alphabet) : key_(key), text_(text), alphabet_(alphabet) {
    encrypting();
    std::cout << "\nЗашифрованный текст: ";
    std::cout << text << std::endl;

    decrypting();
    std::cout << "\nРасшифрованный текст: ";
    std::cout << text << std::endl;
}