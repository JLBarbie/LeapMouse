#include "Utils.hpp"

void
printError(std::string msg) {
    std::cerr << "[ \033[31mERROR\033[0m ] " << msg << std::endl;
    exit(-1);
}

void
printDebug(std::string msg) {
    std::cout << "[ \033[36mDEBUG\033[0m ] " << msg << std::endl;
}


void
printSuccess(std::string msg) {
    std::cout << "[ \033[32mDONE\033[0m ] " << msg << std::endl;
}
