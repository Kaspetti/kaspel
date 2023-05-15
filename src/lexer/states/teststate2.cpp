#include <iostream>

#include "../../../include/lexer/fsmstate.h"

class TestState2 : public FSMState {
public:
    void on() override {
        std::cout << "TestState2 on" << std::endl;
    }

    void off() override {
        std::cout << "TestState2 off" << std::endl;
    }
};
