#include "../include/lexerfsm.h"
#include "../include/startstate.h" 


LexerFSM::LexerFSM(std::string input){
    this->input = input;

    startState = new StartState();
    currentState = startState;
}

LexerFSM::~LexerFSM(){
    delete startState;
}

void LexerFSM::setState(FSMState* state){
    currentState = state;
}

void LexerFSM::run(){
    for (char c : input) {
        currentState->on(*this, c);
    }
}
