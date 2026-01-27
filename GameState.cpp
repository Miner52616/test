#include "GameState.h"
#include "application.h"
#include <iostream>

GameState::GameState(application &app):
    State(app),player_(app.playerTexture_)
{
    player_.setPosition({640,480});
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        player_.setPosition({player_.position_.x,(player_.position_.y)-5});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player_.setPosition({player_.position_.x,(player_.position_.y)+5});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player_.setPosition({player_.position_.x-5,player_.position_.y});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player_.setPosition({player_.position_.x+5,player_.position_.y});
    }
}

void GameState::Render(sf::RenderWindow& window)
{
    player_.drawwindow(window);
}

void GameState::HandleEvent(sf::RenderWindow& window,const sf::Event::Closed)
{
    window.close();
    std::cout<<"window closed";
}