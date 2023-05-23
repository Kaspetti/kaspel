#include <unordered_set>

#include "fsmstate.h"


/**
 * State for reading a keyword from the input stream. This state is entered 
 * when a non whitespace character is encountered in the start state. The
 * keyword is read until a whitespace character is encountered.
 *
 * @author Kaspar Moberg
 */
class KeywordState : public FSMState {
public:
    KeywordState();

    void step(LexerFSM &stateMachine, const char &input) override;

private:
    std::string keyword;

    std::unordered_set<std::string> keywords;

    std::string identifierPattern;
};
