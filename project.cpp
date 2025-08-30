#include "project.h"

#include <cstring>
#include <iostream>
#include <bits/stl_algo.h>

void _help() {

    const std::string RED    = "\033[31m";
    const std::string GREEN  = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string CYAN   = "\033[36m";
    const std::string RESET  = "\033[0m";

    std::cout << CYAN << "============================================\n";
    std::cout << "         Conversor Decimal ⇄ Binário\n";
    std::cout << "====================================================\n" << RESET;

    std::cout << GREEN << "Uso:\n" << RESET
              << "  ./a.out [--parametros] [numero]\n\n";

    std::cout << GREEN << "Parâmetros:\n" << RESET
              << "  " << YELLOW << "--dec2bin ou -b" << RESET << "   Converte decimal para binário\n"
              << "  " << YELLOW << "--bin2dec ou -d" << RESET << "   Converte binário para decimal\n"
              << "  " << YELLOW << "--help" << RESET   << "     Mostra esta tela de ajuda\n\n";

    std::cout << GREEN << "Exemplos:\n" << RESET
              << "  " << CYAN << "./a.out --dec2bin 25" << RESET    << "    # Saída: 11001\n"
              << "  " << CYAN << "./a.out --bin2dec 11001" << RESET << "    # Saída: 25\n"
              << "  " << CYAN << "./a.out --help" << RESET           << "           # Mostra esta tela de ajuda\n\n";

    std::cout << CYAN << "====================================\n" << RESET;
}

void dec2bin(int number) {
    //Versão recursiva
    if (number == 0) {
        return;
    }
    dec2bin(number/2);
    std::cout << number % 2;
}

int bin2dec(int number) {
    int ultimo_digito = {0} , num_dec = {0}, base = {1};

    while (number) {
        ultimo_digito = number % 10;
        number = number / 10;
        num_dec += ultimo_digito * base;
        base = base * 2;
    }

    return num_dec;
}

bool check_number(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void _start(int argc, char** argv) {

    if (argc == 2) {
        std::string param = argv[1];

        if (param == "--help") {
            _help();
        } else if (param == "--dec2bin") {
            std::cout << "Use os parâmetros --dec2bin ou -b seguido de um número decimal inteiro para convertê-lo em binário\n";
            std::cout << "Exemplo: ./a.out --dec2bin 100 (Converte 100 para binário).\n";
        } else if (param == "--bin2dec") {
            std::cout << "Use os parâmetros --bin2dec ou -d seguido de um número binário para convertê-lo em decimal\n";
            std::cout << "Exemplo: ./a.out --bin2dec 1111 (Converte 1111 para decimal).\n";
        } else {
            std::cout << "Parâmetro inválido. Use --help para mais informações.\n";
        }
    }
    else if (argc >= 2) {
        std::string param = argv[1];
        int number        = std::stoi(argv[2]);

        if (!check_number(number)) {
            return;
        }

        if (param == "--dec2bin" || param == "-b") {
            dec2bin(number);
            std::cout << '\n';
        } else if (param == "--bin2dec" || param == "-d") {
            std::cout << bin2dec(number) << '\n';
        } else {
            std::cout << "Parâmetros inválidos. Use --help para mais informações.\n";
        }
    } else {
        std::cout << "Quantidade de parâmetros inválida. Use o parâmetro --help para mais informações." << '\n';
    }
}