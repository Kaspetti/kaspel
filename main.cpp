#include <fstream>
#include <iostream>

#include "lexer/include/lexerfsm.h"


int main() {
    std::ifstream file;
    file.open("test.kl");

    if (file.is_open()) {
        std::string lines;
        std::string line;
        while (getline(file, line)) {
            lines += line;
        }

        LexerFSM fsm = LexerFSM(lines);
        fsm.run();
    }
    else {
        std::cout << "File not found" << std::endl;
    }

    return 0;
}
