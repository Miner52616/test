#include "GameState.h"
#include "application.h"
#include <iostream>

GameState::GameState(application &app):
    State(app),
    frame_(0),
    player_(app.playerTexture_),
    enemy1_(app.enemyTexture_)
{
    player_.setPosition({640,480});
    enemy1_.setPosition({640,100});

    enemy1_.set_start_end(480,216000);
}

void GameState::ProcessEvent(sf::RenderWindow& window,const std::optional<sf::Event> event)
{
    event->visit
    (
        [this,&window](const auto event)
        {
            this->HandleEvent(window,event);
        }
    );
}

void GameState::Update()
{
    player_.Player_update();

    enemy1_.set_exist(frame_);

    frame_++;
}

void GameState::Render(sf::RenderWindow& window)
{
    player_.drawwindow(window);
    enemy1_.drawwindow(window);
}

void GameState::HandleEvent(sf::RenderWindow& window,const sf::Event::Closed)
{
    window.close();
    std::cout<<"window closed";
}