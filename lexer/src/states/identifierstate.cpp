#include <iostream>

#include "../../include/identifierstate.h"

IdentifierState::IdentifierState() {
    identifierRegex = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");
}

void IdentifierState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        if (std::regex_match(identifier, identifierRegex)) {
            stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::IDENTIFIER, identifier));
        }
        else {
            std::cout << "Invalid identifier: " << identifier << std::endl;
        }

        identifier = "";
        stateMachine.setState(stateMachine.startState);
        return;
    }

    identifier += input;
}
