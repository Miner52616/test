#pragma once
#include "state.h"
#include "Player.h"

class GameState:public State
{
private:
    Player player_;

public:
    void ProcessEvent(sf::RenderWindow& window,const std::optional<sf::Event> event) override;
    void Update() override;
    void Render(sf::RenderWindow& window) override;

public:
    GameState(application &app);

protected:
    void HandleEvent(sf::RenderWindow& window,const sf::Event::Closed);
    void HandleEvent(sf::RenderWindow& window,auto){};
};