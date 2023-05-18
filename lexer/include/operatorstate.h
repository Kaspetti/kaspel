#include <iostream>
#include <unordered_set>


#include "fsmstate.h"


class OperatorState : public FSMState {
public:
    OperatorState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    std::unordered_set<char> operators;
};

