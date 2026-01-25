#pragma once
#include "Text.h"

class Page
{
private:
    std::vector<Text> textlist_;
    const sf::Font &font_;

private:
    void addText();

public:
    Page(const sf::Font &font);

public:
    void Render(sf::RenderWindow& window);

    void setTextlistLength(int num);
    void setTextText(int num,const std::string text);
    void setTextPosition(int num,sf::Vector2f position);
    void setTextSize(int num,int size);
    void setTextColor(int num,sf::Color color);
};