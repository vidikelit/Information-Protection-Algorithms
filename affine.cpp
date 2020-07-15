#include <iostream>
#include "affine.h"

void Affine::encrypting() {
    if (nod(key_a_, alphabet_.size()) == 1) {
        int size = alphabet_.size();
        for (auto& word : words_) {
            for (int i = 0; i < size; i++) {
                if (word == alphabet_.at(i)) {
                    word = alphabet_.at((key_a_ * i + key_b_) % size);
                    break;
                }
            }
        }
    }
    else {
        std::cout << "Ключ не простой!" << std::endl;
    }

}

void Affine::decrypting() {
    int size = alphabet_.size();
    int a_inverse = Foo(key_a_, alphabet_.size());
    if (nod(key_a_, alphabet_.size()) == 1) {
        for (auto& word : words_) {
            for (int i = 0; i < size; i++) {
                if (word == alphabet_.at(i)) {
                    if (i >= key_b_) {
                        word = alphabet_.at(a_inverse * (i - key_b_) % size);
                    }
                    else {
                        word = alphabet_.at(a_inverse * (i + size - key_b_) % size);
                    }
                    break;
                }
            }
        }
    }
}

int Affine::nod(int key_a, int alphabet_size) {
    return alphabet_size ? nod(alphabet_size, key_a % alphabet_size) : key_a;
}

int Affine::Foo(int key_a, int alphabet_size) {
    int x, y;
    int gcd = GCD(key_a, alphabet_size, x, y);
    if (gcd != 1) return 1;
    return (x % alphabet_size + alphabet_size) % alphabet_size;
}

int Affine::GCD(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

Affine::Affine(int keyA, int keyB, std::string& alphabet, std::string& words) : key_a_(keyA), key_b_(keyB), alphabet_(alphabet), words_(words) {
    encrypting();
    std::cout << "\nЗашифрованный текст: " << words << std::endl;

    decrypting();
    std::cout << "\nРасшифрованный текст: " << words << std::endl;
}
