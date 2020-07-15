#pragma once
#include <string>

class Feistel {
private:
    std::string& key_;
    std::string& text_;
public:
    char fGamma(char subblock, std::string key, int round);
    void encrypting();
    void decrypting();
    Feistel(std::string& key, std::string& text);
};