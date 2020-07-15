#pragma once
#include <string>

class ServiceManager {
public:
    std::string setLowerLetter(std::string input);
    std::string removeSpace(std::string input);
    std::string shiftText(std::string input, std::string alphabet, int shift);
    int searchNumInput(int num, std::string input, std::string input_search);
    ServiceManager();
};