#pragma once
#include "state.h"

class ManualState:public State
{
private:
    int page_;
public:
    ManualState(application &app);
};
