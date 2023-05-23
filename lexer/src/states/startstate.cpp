#include "../../include/startstate.h"


StartState::StartState() {
    operators = std::unordered_set<char>({
        '+',
        '-',
        '*',
        '/',
        '=',
        '%',
    });

    symbols = std::unordered_set<char>({
        ';',
    });
}


void StartState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        return;
    }

    if (operators.find(input) != operators.end()) {
        stateMachine.setState(stateMachine.operatorState);
    }
    else if (symbols.find(input) != symbols.end()) {
        // TODO: Change to "symbolState". This is temp
        stateMachine.setState(stateMachine.operatorState);
    }
    else {
        stateMachine.setState(stateMachine.keywordState);
    }

    stateMachine.currentState->step(stateMachine, input);
}

