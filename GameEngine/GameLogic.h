#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vec2.hpp> 
#include "Context.h"
#include "Player.h"
#include "GameSettings.h"
#include "SpatialGrid.h"
#include "CollisionTable.h"

class GameLogic {
private:

    Player* player;
    std::vector<std::pair<RenderSnapshot*, BoundingShape*>> static_objects;
    std::pair<RenderSnapshot*, BoundingShape*> unreachable_block;
    std::map<std::pair<int, int>, bool> check_collision_broad_phase();
    void check_collision_narrow_phase_and_resolve(std::map<std::pair<int, int>, bool> interested_collision_pairs);
    SpatialGrid grid{};
    CollisionTable table{};
    float playerspeed = 0.5;
    int player_id = 1;
    int unreachable_block_id = 2;
public:
    void update(Context& context);
    GameLogic();
    ~GameLogic();
};

