#pragma once
#include <string>

class Caesar {
private:
    int key_;
    std::string& alphabet_;
    std::string& words_;

public:
    void encrypting();
    void decrypting();

    Caesar(int key, std::string& alphabet, std::string& words);
};
