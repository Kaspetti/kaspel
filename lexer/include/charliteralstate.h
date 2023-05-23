#include "fsmstate.h"

class CharLiteralState: public FSMState {
public:
    CharLiteralState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    // Is string as we need to be able to handle escape characters
    std::string literal;
};
