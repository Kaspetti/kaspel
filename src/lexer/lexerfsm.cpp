#include "states/teststate1.cpp"
#include "states/teststate2.cpp"

class FSMStateMachine {
public:
    FSMStateMachine(std::string input) {
        this->input = input;
        currentState = testState1;
    }

    ~FSMStateMachine() {
        delete testState1;
        delete testState2;
    }

    void run() {
        currentState->on();
        currentState->off();
        currentState = testState2;
        currentState->on();
        currentState->off();
    }
private:
    std::string input;

    FSMState* testState1 = new TestState1();
    FSMState* testState2 = new TestState2();
    FSMState* currentState;

};

