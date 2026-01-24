#include "ManualState.h"
#include "application.h"
#include <iostream>

ManualState::ManualState(application &app):
    State(app),page_(1)
{
    ;
}