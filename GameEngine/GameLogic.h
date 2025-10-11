#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "Context.h"
#include "Player.h"

class GameLogic {
private:

    Player* player;
public:
    void update(Context& context);
    GameLogic();
    ~GameLogic();
};

