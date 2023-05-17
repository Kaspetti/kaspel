#include "fsmstate.h"

class OperatorState : public FSMState {
public:
    void step(LexerFSM &stateMachine, const char &input) override;
};

