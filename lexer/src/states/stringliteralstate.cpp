#include "../../include/stringliteralstate.h"


StringLiteralState::StringLiteralState() {
    literal = "";
}


void StringLiteralState::step(LexerFSM &stateMachine, const char &input) { 
    if (input == '"') {
        stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::STRING_LITERAL, literal));
        literal = "";
        stateMachine.setState(stateMachine.startState);
        return;
    }

    literal += input;
}
