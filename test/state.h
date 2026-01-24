#pragma once

#include <SFML/Graphics.hpp>
//#include "application.h"
//#include "main.cpp"

class application;

class State
{
public:
    explicit State(application &app):app_(app){}
    virtual ~State()=default;

    virtual void ProcessEvent(sf::RenderWindow& window,const std::optional<sf::Event> event)=0;
    virtual void Update()=0;
    virtual void Render(sf::RenderWindow& window)=0;

    virtual bool blocksUpdate() const { return true; }
    virtual bool blocksRender() const { return true; }

protected:
    application &app_;

//public:
//    virtual void HandleEvent(sf::RenderWindow& window,const sf::Event&)=0;
//    virtual void HandleEvent(sf::RenderWindow& window,const std::optional<sf::Event>& event)=0;
};