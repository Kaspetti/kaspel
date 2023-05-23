#include "../../include/charliteralstate.h"


CharLiteralState::CharLiteralState() {
    literal = "";
}

void CharLiteralState::step(LexerFSM &stateMachine, const char &input) { 
    if (input == '\'') {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::CHAR_LITERAL, literal));
        literal = "";
        stateMachine.setState(stateMachine.startState);
        return;
    }

    literal += input;
}
