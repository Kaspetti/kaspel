#include <iostream>

#include "../../include/fsmstate.h"

class TestState1 : public FSMState {
public:
    void on() override {
        std::cout << "TestState1 on" << std::endl;
    }

    void off() override {
        std::cout << "TestState1 off" << std::endl;
    }
};
