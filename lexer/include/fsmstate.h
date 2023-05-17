#ifndef FSMSTATE_H
#define FSMSTATE_H

#include <string>

class LexerFSM;
#include "lexerfsm.h"


/**
 * Abstract class for a state in the FSM.
 *
 * @see LexerFSM
 * @author Kaspar Moberg
 */
class FSMState {
public:
    virtual ~FSMState() = default;

    /**
     * Step the state machine.
     *
     * @param stateMachine The state machine to step.
     * @param input The input character.
     */
    virtual void step(LexerFSM &stateMachine, const char &input) = 0;
};
#endif //FSMSTATE_H
