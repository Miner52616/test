#pragma once
#include "TextState.h"

constexpr int ManPageNum=5;

class ManualState:public TextState<ManualState>
{
public:
    using TextState<ManualState>::HandleEvent;
    ManualState(application &app,const sf::Font &font);
    void HandleEvent(sf::RenderWindow& window,const sf::Event::KeyPressed&);
};