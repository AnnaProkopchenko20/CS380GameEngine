#include "GameLogic.h"
#include "RenderSnapshot.h"
#include <random>

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
	std::vector<RenderSnapshot> snapshots;
	
	for (auto& obj : static_objects) {
		snapshots.push_back(obj);
	}
	snapshots.push_back(player->get_object_snapshot());
	context.update(snapshots);
};

int generate_random_positive_int(int min_value, int max_value) {
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(min_value, max_value);
	int mean = uniform_dist(e1);
	return mean;
}

glm::vec2 generate_random_coord() {
	int x = generate_random_positive_int(0,GameSettings::screen_width_px);
	int y = generate_random_positive_int(0,GameSettings::screen_height_px);
	return glm::vec2(x,y);
}


GameLogic::GameLogic() {
	int obj_count = 100;
	for (int i = 0; i < obj_count; ++i) {
		
		static_objects.push_back(RenderSnapshot(generate_random_coord(), glm::vec2(0, 0), "donut.png","circle"));
	}
	float playerspeed = 0.5;
	int id = 1;
	player = new Player(playerspeed, id);
};
GameLogic::~GameLogic() {
	delete player;
};