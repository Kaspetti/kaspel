#ifndef LEXERFSM_H
#define LEXERFSM_H

#include <string>
#include <vector>
#include <tuple>

class FSMState;
#include "fsmstate.h"


/**
 * The different types of tokens that can be found in the input.
 */
enum class TokenType {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    UNKNOWN
};


using Token = std::tuple<TokenType, std::string>;


/**
 *  The main class of the lexer FSM. This class is responsible for running the 
 *  FSM and keeping track of the current state.
 *
 *  @author Kaspar Moberg
 */
class LexerFSM {
public:
    LexerFSM(std::string input);

    ~LexerFSM();

    /**
     * Run the FSM on the input string.
     */
    void run();

    /**
     * Set the current state of the FSM.
     *
     * @param state The new state.
     */
    void setState(FSMState* state);

    /**
     * Add a token to the list of tokens.
     *
     * @param token The token to add.
     */
    void addToken(Token token);

    /**
     * Get the string representation of a token.
     *
     * @param token The token to convert.
     * @return The string representation of the token.
     */
    std::string tokenToString(Token token);

    std::vector<Token> getTokens(); 
    

    // The different states of the FSM.
    FSMState* startState;
    FSMState* keywordState;
    FSMState* identifierState;

private:
    std::string input;
    
    FSMState* currentState;

    std::vector<Token> tokens;
};
#endif //LEXERFSM_H
