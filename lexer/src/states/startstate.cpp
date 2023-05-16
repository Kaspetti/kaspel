#include "../../include/startstate.h"

#include <iostream>

void StartState::on(LexerFSM &stateMachine, const char &input) {
    std::cout << input << std::endl;
}

void StartState::off() {

}

