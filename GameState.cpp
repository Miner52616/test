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

    for(auto it=player_bulletlist.begin();it!=player_bulletlist.end();++it)
    {
        it->setPosition({it->position_.x,it->position_.y-12});
    }
    player_bulletlist.erase
    (
        std::remove_if
        (
            player_bulletlist.begin(),player_bulletlist.end(),
            [](const Bullet &bullet)
            {
                if((bullet.position_.x<0)||(bullet.position_.y<0)||(bullet.position_.x>1280)||(bullet.position_.y>960))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        ),
        player_bulletlist.end()
    );
    if(player_.request_shoot_)
    {
        player_bulletlist.emplace_back(app_.bulletTexture_,player_.position_);
        player_.request_shoot_=0;
    }

    frame_++;
}

void GameState::Render(sf::RenderWindow& window)
{
    player_.drawwindow(window);
    enemy1_.drawwindow(window);

    for(auto it=player_bulletlist.begin();it!=player_bulletlist.end();++it)
    {
        it->drawwindow(window);
        it->setPosition({it->position_.x,it->position_.y-12});
    }
}

void GameState::HandleEvent(sf::RenderWindow& window,const sf::Event::Closed)
{
    window.close();
    std::cout<<"window closed";
}