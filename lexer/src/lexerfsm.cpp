#include <iostream>

#include "../include/lexerfsm.h"
#include "../include/startstate.h"
#include "../include/keywordstate.h"
#include "../include/identifierstate.h"
#include "../include/operatorstate.h"


LexerFSM::LexerFSM(std::string input){
    this->input = input;

    startState = new StartState();
    keywordState = new KeywordState();
    identifierState = new IdentifierState();
    operatorState = new OperatorState();
    currentState = startState;
}

LexerFSM::~LexerFSM(){
    delete startState;
    delete keywordState;
    delete identifierState;
    delete operatorState;
}

void LexerFSM::setState(FSMState* state){
    currentState = state;
}

void LexerFSM::run(){
    for (char c : input) {
        currentState->step(*this, c);
    }
}

void LexerFSM::addToken(Token token) {
    tokens.push_back(token);
}

std::vector<Token> LexerFSM::getTokens() {
    return tokens;
}

std::string LexerFSM::tokenToString(Token token) {
    std::string output;

    switch (std::get<0>(token)) {
        case TokenType::KEYWORD:
            output = "KEYWORD";
            break;
        case TokenType::IDENTIFIER:
            output = "IDENTIFIER";
            break;
        case TokenType::OPERATOR:
            output = "OPERATOR";
            break;
        default:
            output = "UNKNOWN";
            break;
    }

    return output + ": " + std::get<1>(token);
}
