#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    const sf::Texture &texture_;


public:
    sf::Vector2f position_;
    int hitbox_r_;

protected:
    sf::CircleShape hitbox_;
    sf::Sprite picture_;

public:
    void setPosition();
    void setPosition(sf::Vector2f position);

    virtual void drawwindow(sf::RenderWindow& window);

public:
    Entity(const sf::Texture &texture);
};