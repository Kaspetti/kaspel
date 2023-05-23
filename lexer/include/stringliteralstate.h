#include "fsmstate.h"

class StringLiteralState: public FSMState {
public:
    StringLiteralState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    std::string literal;
};
