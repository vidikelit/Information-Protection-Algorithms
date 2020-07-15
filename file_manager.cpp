#include <iostream>
#include <fstream>
#include "service_manager.h"
#include "file_manager.h"

std::string FileManager::reader(std::string input, std::string path) {
    ServiceManager serviceManager;
    std::ifstream in_input(path);
    if (in_input.is_open()) std::getline(in_input, input);
    in_input.close();
    return serviceManager.setLowerLetter(input);
}
FileManager::FileManager() {}