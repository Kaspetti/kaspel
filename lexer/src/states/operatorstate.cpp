#include <iostream>


#include "../../include/operatorstate.h"


OperatorState::OperatorState() {
    operators = std::unordered_set<std::string>({
        "+",
        "-",
        "*",
        "/",
        "//",
        "%",
        "++",
        "--",
    });

    operatorChars = std::unordered_set<char>({
        '+',
        '-',
        '*',
        '/',
        '=',
    }); 

    curOperator = "";
}


void OperatorState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        return;
    }
    else if (operatorChars.find(input) != operatorChars.end()) {
        curOperator += input; 
        return;
    }
    else {
        if (curOperator != "") {
            stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::OPERATOR, curOperator));
            curOperator = "";
        }

        stateMachine.setState(stateMachine.startState);
        stateMachine.currentState->step(stateMachine, input);
        return;
    }
}  

