#include "project.h"

void _help() {
    std::cout << "Uso: " <<
                 "--dec2bin Para converter decimal para binário";
                 "--bin2dec Para converter binário para decimal";

}

void _start(int argc, char** argv) {
    if (argc > 2) {
        std::cout << "Chama as funções de conversão" << '\n';
    } else {
        _help();
    }
}