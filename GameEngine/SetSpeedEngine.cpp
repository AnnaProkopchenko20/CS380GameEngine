#include "SetSpeedEngine.h"

void SetSpeedEngine::update(int delta_time_in_miliseconds) {
	_coord += _rotation * _speed * (float)delta_time_in_miliseconds;
};

void SetSpeedEngine::change_rotation(const glm::vec2& new_rotation) {
	_rotation = glm::vec2(new_rotation);
};

SetSpeedEngine::SetSpeedEngine(float speed,const glm::vec2& rotation,const glm::vec2& coord) {
	_speed = speed;
	_rotation = glm::vec2(rotation);
	_coord = glm::vec2(coord);
};

SetSpeedEngine::~SetSpeedEngine() {

};

std::pair<glm::vec2, glm::vec2> SetSpeedEngine::get_engine_snapshot() {
	return std::pair<glm::vec2, glm::vec2>(_rotation, _coord);
};