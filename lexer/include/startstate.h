#include "fsmstate.h"


/**
 * The start state of the FSM. This is the initial state of the FSM and 
 * transitions to the the keyword state when a non whitespace character is 
 * encountered.
 *
 * @author Kaspar Moberg
 */
class StartState: public FSMState {
public:
    void step(LexerFSM &stateMachine, const char &input) override;
};

