#pragma once
#include "state.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class GameState:public State
{
private:
    long long int frame_;
    Player player_;
    Enemy enemy1_;

    std::vector<Bullet> player_bulletlist;

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