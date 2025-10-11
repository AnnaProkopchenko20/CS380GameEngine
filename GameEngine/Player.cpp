#include "Player.h"

void Player::move(const glm::vec2& rotation) {
	engine.change_rotation(rotation);
	engine.update(delta_time);
};
void Player::move_up() {
	move(up);
};
void Player::move_down() {
	move(down);
};
void Player::move_left() {
	move(left);
};
void Player::move_right() {
	move(right);
};
Player::Player(float speed, int id) : engine(speed, default_rotation, default_coord), id(id), delta_time{} {
};
Player::~Player() {};

ObjectSnapshot Player::get_object_snapshot() {
	auto snapshot = engine.get_engine_snapshot();
	return ObjectSnapshot(snapshot.second, ObjectType::Player, id, snapshot.first);
}

void Player::update_delta(int delta_time_in_miliseconds) {
	delta_time = delta_time_in_miliseconds;
};
