#pragma once
#include "Entity.h"

class Player:public Entity
{
private:
    bool hitbox_exist_;
    int speed_;

public:
    Player(const sf::Texture &texture);

    void Player_update();
    void drawwindow(sf::RenderWindow& window) override;
};