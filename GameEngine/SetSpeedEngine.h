#pragma once

#include <vec2.hpp> 
#include <utility>


class SetSpeedEngine {
private:
    float _speed;
    glm::vec2 _rotation;
    glm::vec2 _coord;
public:
    void update(int delta_time_in_miliseconds);
    void change_rotation(const glm::vec2& new_rotation);
    std::pair<glm::vec2,glm::vec2> get_engine_snapshot();

    SetSpeedEngine(float speed, const glm::vec2& rotation,const glm::vec2& coord);
    ~SetSpeedEngine();
};

