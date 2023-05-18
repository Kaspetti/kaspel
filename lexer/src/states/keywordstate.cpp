#include <iostream>

#include "../../include/keywordstate.h"


KeywordState::KeywordState() {
    keywords = {
        "int"
    };
}


void KeywordState::step(LexerFSM &stateMachine, const char &input) {
    if (input == ' ') {
        if (keywords.find(keyword) == keywords.end()) {
            std::cout << "Invalid keyword: " << keyword << std::endl;
        }
        else  {
            stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::KEYWORD, keyword));
        }

        keyword = "";
        stateMachine.setState(stateMachine.operatorState);
        return; 
    } 

    keyword += input;
}
