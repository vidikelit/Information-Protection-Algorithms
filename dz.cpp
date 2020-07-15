#include <iostream>
#include <string>
#include <ctime>
#include "file_manager.h"
#include "caesar.h"
#include "affine.h"
#include "vegenere.h"
#include "gamm.h"
#include "feistel.h"
#include "rsa.h"

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    std::string text;
    std::string alphabet;

    FileManager fileManager;
    text = fileManager.reader(text, "text.txt");
    alphabet = fileManager.reader(alphabet, "alphabet.txt");

    int n_case;
    std::cout << "1. Шифр Цезаря; 2. Аффинный шифр; 3. Виженер, 4. Гаммирование; 5. Фейстель; 6. RSA шифр" << std::endl;
    std::cout << "Выберите метод: ";
    std::cin >> n_case;
    if (n_case == 1) {
        int key;
        std::cout << "\nВведите ключ (цифра): ";
        std::cin >> key;
        Caesar caesar(key, alphabet, text);
    }
    else if (n_case == 2) {
        int key_a, key_b;
        std::cout << "\nВведите ключ A и B (цифра) ";
        std::cin >> key_a >> key_b;
        Affine affine(key_a, key_b, alphabet, text);
    }
    else if (n_case == 3) {
        std::string key_string;
        std::cout << "\nВведите ключ (текст): ";
        std::cin >> key_string;
        Vegenere vegenere(key_string, text, alphabet);
    }
    else if (n_case == 4) {
        std::string key_string;
        std::cout << "\nВведите ключ (текст): ";
        std::cin >> key_string;
        Gamm gamm(key_string, text, alphabet);
    }
    else if (n_case == 5) {
        std::string key_string;
        std::cout << "\nВведите ключ (цифра): ";
        std::cin >> key_string;
        Feistel Feistel(key_string, text);
    }
    else if (n_case == 6) {
        RSA rsa;
    }
}