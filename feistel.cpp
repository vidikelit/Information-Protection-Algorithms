#include <iostream>
#include "feistel.h"

void Feistel::encrypting() {
    char temp = '0', l = '0', r = '0';
    for (unsigned int i = 0; i < text_.size(); i += 2)
    {
        l = text_[i];
        r = text_[i + 1];
        for (int i = 0; i < key_.size(); i++)
        {
            temp = r ^ fGamma(l, key_, i);
            r = l;
            l = temp;
        }
        text_[i] = l;
        text_[i + 1] = r;
    }
}
void Feistel::decrypting() {
    char temp = '0', l = '0', r = '0';
    for (unsigned int i = 0; i < text_.size(); i += 2) // ������������� ����� �� 2 �������
    {
        l = text_[i];
        r = text_[i + 1];
        for (int i = key_.size() - 1; i >= 0; i--)  // n �������
        {
            temp = l ^ fGamma(r, key_, i);
            l = r;
            r = temp;
        }
        text_[i] = l;
        text_[i + 1] = r;
    }
}
char Feistel::fGamma(char subblock, std::string key, int round) {
    return (subblock * key[round]) % static_cast<char>(pow(2, round) + 1);
}
Feistel::Feistel(std::string& key, std::string& text) : key_(key), text_(text) {
    encrypting();
    std::cout << "\n������������� �����: ";
    std::cout << text << std::endl;

    decrypting();
    std::cout << "\n�������������� �����: ";
    std::cout << text << std::endl;
}