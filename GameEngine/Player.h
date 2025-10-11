#pragma once

#include "Object.h"
#include "SetSpeedEngine.h"

class Player : public Object {
private:
    int id;
    int delta_time;

    const glm::vec2 default_rotation = glm::vec2(0, 1);
    const glm::vec2 default_coord = glm::vec2(0, 1);
    const glm::vec2 up = glm::vec2(0, -1);
    const glm::vec2 down = glm::vec2(0, 1);
    const glm::vec2 left = glm::vec2(-1, 0);
    const glm::vec2 right = glm::vec2(1, 0);

    SetSpeedEngine engine;
    void move(const glm::vec2& rotation);

public:
    void update_delta(int delta_time_in_miliseconds);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    Player(float speed, int id);
    ~Player();
    ObjectSnapshot get_object_snapshot();

    Player& operator=(const Player& other) {
        engine = other.engine;
        id = other.id;
        delta_time = other.delta_time;
        return *this;
    }
 
};

