#include "GameLogic.h"
#include "ObjectSnapshot.h"

void GameLogic::update(Context& context) {

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
	std::vector<ObjectSnapshot> snapshots;
	snapshots.push_back(player->get_object_snapshot());
	context.update(snapshots);
};

GameLogic::GameLogic() {
	float playerspeed = 0.5;
	int id = 1;
	player = new Player(playerspeed, id);
};
GameLogic::~GameLogic() {
	delete player;
};