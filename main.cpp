#include "lexer/src/lexerfsm.cpp"

int main() {
    FSMStateMachine fsm = FSMStateMachine("test");
    fsm.run();

    return 0;
}
