#include <iostream>
#include "caesar.h"

void Caesar::encrypting() {
    int size = alphabet_.size();
    for (auto& word : words_) {
        for (int i = 0; i < size; i++) {
            if (word == alphabet_.at(i)) {
                word = alphabet_.at((i + key_) % size);
                break;
            }
        }
    }
}

void Caesar::decrypting() {
    int size = alphabet_.size();
    for (auto& word : words_) {
        for (int i = 0; i < size; i++) {
            if (word == alphabet_.at(i)) {
                if (i >= key_) {
                    word = alphabet_.at((i - key_) % size);
                }
                else {
                    word = alphabet_.at((i + size - key_) % size);
                }
                break;
            }
        }
    }
}

Caesar::Caesar(int key, std::string& alphabet, std::string& words) : key_(key), alphabet_(alphabet), words_(words) {
    encrypting();
    std::cout << "\nЗашифрованный текст: " << words << std::endl;

    decrypting();
    std::cout << "\nРасшифрованный текст: " << words << std::endl;
}
