#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "Context.h"
#include "Player.h"
#include "GameSettings.h"

class GameLogic {
private:

    Player* player;
    std::vector<RenderSnapshot> static_objects;
public:
    void update(Context& context);
    GameLogic();
    ~GameLogic();
};

