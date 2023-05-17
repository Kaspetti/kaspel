#include <iostream>

#include "../../include/identifierstate.h"

IdentifierState::IdentifierState() {
    std::string startCharsStr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    std::string validCharsStr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

    startChars = std::unordered_set<char>(startCharsStr.begin(), startCharsStr.end()); 
    validChars = std::unordered_set<char>(validCharsStr.begin(), validCharsStr.end());
}

void IdentifierState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::IDENTIFIER, identifier));

        identifier = "";
        stateMachine.setState(stateMachine.operatorState);
        return;
    }

    if (identifier == "") {
        if (startChars.find(input) == startChars.end()) {
            std::cout << "Invalid identifier start character: " << input << std::endl;
            return;
        }
    }
    else {
        if (validChars.find(input) == validChars.end()) {
            std::cout << "Invalid identifier character: " << input << std::endl;
            return;
        }
    }

    identifier += input;
}
