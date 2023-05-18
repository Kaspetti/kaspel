#include <iostream>


#include "../../include/operatorstate.h"


OperatorState::OperatorState() {
    operators = std::unordered_set<char>({
        '+',
        '-',
        '*',
        '/',
        '=',
    }); 
}


void OperatorState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        return;
    }
    else if (operators.find(input) == operators.end()) {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::OPERATOR, input));
    
        return;
    }

    std::cout << input << std::endl;
}  

