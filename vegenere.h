#pragma once
#include <string>

class Vegenere {
private:
    const double IOC = 0.0667;
    std::string& key_;
    std::string& text_;
    std::string& alphabet_;

    std::string key_dec_;
public:
    void encrypting();
    void decrypting();
    double indexOfCoincidence(int shift, std::string input);
    Vegenere(std::string& key, std::string& text, std::string& alphabet);
};