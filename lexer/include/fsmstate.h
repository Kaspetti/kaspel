#ifndef FSMSTATE_H
#define FSMSTATE_H

#include <string>

class LexerFSM;
#include "lexerfsm.h"

class FSMState {
public:
    virtual ~FSMState() = default;

    virtual void on(LexerFSM &stateMachine, const char &input) = 0;

    virtual void off() = 0;
};
#endif //FSMSTATE_H
