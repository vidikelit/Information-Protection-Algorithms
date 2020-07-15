#pragma once
#include <string>

class Affine {
private:
    int key_a_;
    int key_b_;
    std::string& alphabet_;
    std::string& words_;

public:
    void encrypting();
    void decrypting();
    int nod(int key_a, int alphabet_size);
    int Foo(int key_a, int alphabet_size);
    int GCD(int a, int b, int& x, int& y);

    Affine(int keyA, int keyB, std::string& alphabet, std::string& words);
};