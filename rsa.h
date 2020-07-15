#pragma once
#include <string>

class RSA {
private:
    int e, n, d, crypt_number, m, number;
public:
    void generateKey();
    void encrypting();
    void decrypting();
    bool isPrime(int number);
    int isEPrime(int number, int f);
    int getRandPrime();
    int getRandEPrime(int f);
    int ModInverse(int e, int modulus);
    int ModPow(int val, int exponent, int modulus);
    RSA();
};