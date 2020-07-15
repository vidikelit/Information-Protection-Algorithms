#include <algorithm>
#include "service_manager.h"

std::string ServiceManager::setLowerLetter(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return input;
}
std::string ServiceManager::removeSpace(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
    return input;
}
std::string ServiceManager::shiftText(std::string input, std::string alphabet, int shift) {
    for (auto& word : input) {
        for (unsigned int i = 0; i < alphabet.size(); i++) {
            if (word == alphabet.at(i)) {
                word = alphabet.at((i + shift) % alphabet.size());
                break;
            }
        }
    }
    return input;
}
int ServiceManager::searchNumInput(int num, std::string input, std::string input_search) {
    for (unsigned int i = 0; i < input_search.size(); i++) {
        if (input[num] == input_search[i]) {
            return i;
        }
    }
    return 0;
}
ServiceManager::ServiceManager() {}