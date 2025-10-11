#include "GameEngine.h"
#include "ObjectSnapshot.h"

void GameEngine::update(Context& context) {

	player->update_delta(context.get_frame_delta());

	auto commands = context.get_commands();
	for (auto command : commands) {
		switch (command) {
		case Command::UP:
			player->move_up();
			break;
		case Command::DOWN:
			player->move_down();
			break;
		case Command::LEFT:
			player->move_left();
			break;
		case Command::RIGHT:
			player->move_right();
			break;
		}
		
	}
	std::vector<ObjectSnapshot> snapshots = std::vector<ObjectSnapshot>();
	snapshots.push_back(player->get_object_snapshot());
	context.update(snapshots);
};

GameEngine::GameEngine() {
	float playerspeed = 0.5;
	int id = 1;
	player = new Player(playerspeed, id);
};
GameEngine::~GameEngine() {};