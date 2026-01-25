#pragma once
#include "state.h"
#include "Page.h"

//constexpr int ManPageNum=5;

template<typename Derived>
class TextState:public State
{
protected:
    int focus_;
    std::vector<Page> pagelist_;

protected:
    void HandleEvent(sf::RenderWindow& window,const sf::Event::Closed&);
    void HandleEvent(sf::RenderWindow& window,const auto&){};

public:
    void setPagelistLength(int length);

public:
    TextState(application &app,const sf::Font &font,int PageNum);
    void ProcessEvent(sf::RenderWindow& window,const std::optional<sf::Event> event) override;
    void Update() override;
    void Render(sf::RenderWindow& window) override;
};

#include "TextState.ipp"