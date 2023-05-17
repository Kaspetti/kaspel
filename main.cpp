#include <fstream>
#include <iostream>

#include "lexer/include/lexerfsm.h"


int main(int argc, char* argv[]) {
    std::string path = "";

    if (argc > 1) {
        path = argv[1];
    }

    std::ifstream file;
    file.open(path);

    if (file.is_open()) {
        std::string lines;
        std::string line;
        while (getline(file, line)) {
            lines += line;
        }

        LexerFSM fsm = LexerFSM(lines);
        fsm.run();

        for (Token token : fsm.getTokens()) {
            std::cout << fsm.tokenToString(token) << std::endl;
        }
    }
    else {
        std::cout << "File not found: " << path << std::endl;
    }

    return 0;
}
