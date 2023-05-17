#include <unordered_set>

#include "fsmstate.h"

class IdentifierState : public FSMState {
public:
    IdentifierState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    std::string identifier; 

    std::unordered_set<char> startChars;
    std::unordered_set<char> validChars;
};
