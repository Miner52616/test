#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

constexpr int befocused=1;
constexpr int not_befocused=0;

constexpr int locked=1;
constexpr int unlocked=0;

class Button
{
private:
    int focused_;
    int locked_;
    sf::Font font_;
    sf::Text text_;
public:
    Button();

public:
    sf::Text getButtonText_();
    int getButtonLocked();
    void setButtonText(const std::string text);
    void setButtonPosition(sf::Vector2f position);
    void setButtonFocused(int focus);
    void setButtonLock(int lock);
    void updateButton();
};