#include <iostream>
#include "rsa.h"

void RSA::generateKey() {
    int q;
    int p = getRandPrime();
    while (1) {
        q = getRandPrime();
        if (p != q) break;
    }

    // открытый ключ - n
    n = p * q;
    int f = (p - 1) * (q - 1);

    e = getRandEPrime(f);

    // секретный ключ - d
    d = ModInverse(e, f);

    std::cout << "N открытый ключ: " << n << std::endl;
    std::cout << "E открытый ключ: " << e << std::endl;
    std::cout << "D закрытый ключ: " << d << std::endl;
}

void RSA::encrypting() {
    // генерируем случайное число - исходный текст
    number = rand() % n;
    crypt_number = ModPow(number, e, n);
    std::cout << "Случайный ключ: " << crypt_number << std::endl;
}
void RSA::decrypting() {
    int decrypt_number = ModPow(crypt_number, d, n);
    std::cout << "Расшифрованное число: " << decrypt_number << std::endl;
    std::cout << "Случайное число: " << number << std::endl;
    if (number == decrypt_number) {
        std::cout << "Успешно!" << std::endl;
    }
    else {
        std::cout << "Провал!" << std::endl;
    }
}
bool RSA::isPrime(int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}
int RSA::isEPrime(int number, int f) {
    int a = f;
    int b = number;
    while (b > 0) {
        int q = a / b;
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;
    return a == 1;
}
int RSA::getRandPrime() {
    while (true) {
        int number = rand() % 100 + 10;
        if (isPrime(number)) return number;
    }
}
int RSA::getRandEPrime(int f) {
    while (1) {
        int number = rand() % f;
        if (isEPrime(number, f)) return number;
    }
}
int RSA::ModInverse(int e, int modulus) {
    for (int d = 1; d <= 0x7FFFFFFF; d++) {
        long prod = (e * d) % modulus;
        if (prod == 1) return d;
    }
    return 0;
}
int RSA::ModPow(int val, int exponent, int modulus) {
    long result = 1;
    for (int i = 1; i <= exponent; i++) result = (result * val) % modulus;
    return (int)result;
}
RSA::RSA() {
    generateKey();
    encrypting();
    decrypting();
}