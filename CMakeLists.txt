cmake_minimum_required(VERSION 3.26)
project("KaspeL")

set(SOURCES
    main.cpp
    lexer/src/lexerfsm.cpp
    lexer/src/states/startstate.cpp
    lexer/src/states/keywordstate.cpp
    lexer/src/states/identifierstate.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
