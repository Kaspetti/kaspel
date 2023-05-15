#ifndef FSMSTATE_H
#define FSMSTATE_H

class FSMState {
public:
    virtual void on() = 0;

    virtual void off() = 0;

    virtual ~FSMState() = default;
};
#endif //FSMSTATE_H
