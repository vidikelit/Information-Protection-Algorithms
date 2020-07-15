#pragma once
#include <string>

class Gamm {
private:
    std::string& key_;
    std::string& text_;
    std::string& alphabet_;
public:
    void encrypting();
    void decrypting();
    Gamm(std::string& key, std::string& text, std::string& alphabet);
};