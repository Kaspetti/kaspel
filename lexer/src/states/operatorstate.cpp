#include <iostream>


#include "../../include/operatorstate.h"

void OperatorState::step(LexerFSM &stateMachine, const char &input) {
    std::cout << "Operator: " << input << std::endl;
}  

