#include "Player.h"

Player::Player(const sf::Texture &texture):
    Entity(texture),hitbox_exist_(false),speed_(15)
{
    ;
}

void Player::drawwindow(sf::RenderWindow& window)
{
    window.draw(picture_);
    if(hitbox_exist_)
    {
        window.draw(hitbox_);
    }
}

void Player::Player_update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        setPosition({position_.x,(position_.y)-speed_});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        setPosition({position_.x,(position_.y)+speed_});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        setPosition({position_.x-speed_,position_.y});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        setPosition({position_.x+speed_,position_.y});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
    {
        hitbox_exist_=true;
        speed_=5;
    }
    else
    {
        hitbox_exist_=false;
        speed_=15;
    }
}