#include "../../include/startstate.h"


#include <iostream>


StartState::StartState() {
    operators = std::unordered_set<char>({
        '+',
        '-',
        '*',
        '/',
        '=',
        '%',
    });

    delimiters = std::unordered_set<char>({
        '(',
        ')',
        '{',
        '}',
        ';',
        ',',
    });
}


void StartState::step(LexerFSM &stateMachine, const char &input) {
    if (std::isspace(input)){
        return;
    }

    if (operators.find(input) != operators.end()) {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::OPERATOR, std::string(1, input)));
    }
    else if (delimiters.find(input) != delimiters.end()) {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::DELIMITER, std::string(1, input)));
    }
    else if (input == '\''){
        std::cout << "Char literal" << std::endl;
    }
    else if (input == '"'){
        stateMachine.setState(stateMachine.stringLiteralState);
    }
    else {
        stateMachine.setState(stateMachine.keywordState);
        stateMachine.keywordState->step(stateMachine, input);
    }
}

