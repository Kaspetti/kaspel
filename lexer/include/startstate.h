#include "fsmstate.h"

class StartState: public FSMState {
public:
    void on(LexerFSM &stateMachine, const char &input) override;

    void off() override;
};

