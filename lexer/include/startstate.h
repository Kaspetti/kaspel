#include "fsmstate.h"
#include <unordered_set>


/**
 * The start state of the FSM. Transisitons to the appropriate state when a non whitespace character is encountered;
 * @author Kaspar Moberg
 */
class StartState: public FSMState {
public:
    StartState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    std::unordered_set<char> operators;
    std::unordered_set<char> symbols;
};

