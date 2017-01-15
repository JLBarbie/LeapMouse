#include "Util.hpp"

Util::Util() {

}

Util::~Util() {

}

void Util::printError(std::string msg) {
    std::cerr << "[ \033[31mERROR\033[0m ] " << msg << std::endl;
    exit(-1);
}
