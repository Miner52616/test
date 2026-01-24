#pragma once

#include <SFML/Graphics.hpp>
//#include "Menustate.h"
#include "StateStack.h"

class StateStack;

class application
{
private:
    sf::RenderWindow window_;
public:
    StateStack stack_;
//    std::unique_ptr<State> current_state_=std::make_unique<MenuState>();

public:
    application();
    bool IsRunning() const;
    void ProcessEvent();
    void Update();
    void Render();
};