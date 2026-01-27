#include "state.h"
#include "application.h"
#include <iostream>

State::State(application &app):
    app_(app),font_(app.mainFont_)
{
    ;
}