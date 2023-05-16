#ifndef LEXERFSM_H
#define LEXERFSM_H

#include <string>

class FSMState;
#include "fsmstate.h"


class LexerFSM {
public:
    LexerFSM(std::string input);

    ~LexerFSM();

    void run();

    void setState(FSMState* state);

    FSMState* startState;
    FSMState* testState;

private:
    std::string input;
    
    FSMState* currentState;
};
#endif //LEXERFSM_H
