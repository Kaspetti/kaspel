#include "../../include/startstate.h"

#include <iostream>


void StartState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        return;
    }

    stateMachine.setState(stateMachine.keywordState);
    stateMachine.keywordState->step(stateMachine, input);
}

