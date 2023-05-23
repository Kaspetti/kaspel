#include <iostream>
#include <regex>

#include "../../include/keywordstate.h"


KeywordState::KeywordState() {
    keywords = {
        "int"
    };

    identifierPattern = R"([a-zA-z_]+[a-zA-z0-9_]*)";
}


void KeywordState::step(LexerFSM &stateMachine, const char &input) {
    if (std::isspace(input)) {
        if (keywords.find(keyword) == keywords.end()) {
            std::regex regex(identifierPattern);
            std::smatch match;

            if (std::regex_match(keyword, match, regex)) {
                stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::IDENTIFIER, keyword));
            }
            else {
                std::cout << "Invalid identifier: " << keyword << std::endl;
            }
        }
        else  {
            stateMachine.addToken(std::tuple<TokenType, std::string>(TokenType::KEYWORD, keyword));
        }

        keyword = "";
        stateMachine.setState(stateMachine.startState);
        return; 
    } 

    keyword += input;
}
