#include "GameLogic.h"
#include "RenderSnapshot.h"
#include <random>
#include <vec2.hpp> 
#include "BoundingShape.h"
#include "Circle.h"
#include "AABBShape.h"


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

	check_collision_narrow_phase_and_resolve(check_collision_broad_phase());
	for (auto& obj : static_objects) {
		snapshots.push_back(*(obj.first));
	}
	snapshots.push_back(player->get_object_snapshot());
	snapshots.push_back(*(unreachable_block.first));
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
	int x = generate_random_positive_int(100,GameSettings::screen_width_px - 100);
	int y = generate_random_positive_int(100,GameSettings::screen_height_px - 100);
	return glm::vec2(x,y);
}

std::map<std::pair<int, int>, bool> GameLogic::check_collision_broad_phase() {
	
	std::vector<BoundingShape*> snapshots;
	std::map<std::pair<int, int>, bool> interested_results;
	for (auto& obj : static_objects) {
		snapshots.push_back(obj.second);
		interested_results[{player_id, obj.second->_id}] = false;
		interested_results[{player_id, unreachable_block_id}] = false;
	}
	snapshots.push_back(player->get_object_bounding_shape());
	snapshots.push_back(unreachable_block.second);
	grid.clear();
	grid.fill(snapshots,table);

	return grid.get_potential_collision_pairs(interested_results);
}

void GameLogic::check_collision_narrow_phase_and_resolve(std::map<std::pair<int, int>, bool> interested_collision_pairs) {

	for (auto it = static_objects.begin(); it != static_objects.end(); ) {
		if (interested_collision_pairs.at({ player_id, it->second->_id }) && table.check_collision(player->get_object_bounding_shape(), it->second)) {
			it = static_objects.erase(it);
		}
		else {
			++it;
		}
	}

	if (interested_collision_pairs.count({ player_id, unreachable_block_id }) &&
		interested_collision_pairs.at({ player_id, unreachable_block_id })) {

		if (table.check_collision(player->get_object_bounding_shape(), unreachable_block.second)) {
			glm::vec2 slide_vector = CollisionAlgorithms::resolve_aabb_and_aabb_wall(player->get_object_bounding_shape(), unreachable_block.second);
			player->move(slide_vector);
		}
	}
}



std::pair<RenderSnapshot*, BoundingShape*> donut_factory(int id) {
	glm::vec2 coord = generate_random_coord();
	return std::make_pair(new RenderSnapshot(coord, glm::vec2(0, 0), "donut.png", "circle"),new Circle(id,coord,GameSettings::donut_radius));
}

GameLogic::GameLogic() {
	int obj_count = 20;
	for (int i = 0; i < obj_count; ++i) {
		int donut_id = i + 3;
		static_objects.push_back(donut_factory(donut_id));
	}
	glm::vec2 center_coord(GameSettings::screen_width_px / 2, GameSettings::screen_height_px / 2);
	unreachable_block = std::make_pair(new RenderSnapshot(center_coord, glm::vec2(0, 0), "block.png","rectangle"), new AABBShape(unreachable_block_id, GameSettings::unreachable_block_size, center_coord));

	player = new Player(playerspeed, player_id);
};
GameLogic::~GameLogic() {
	delete player;
	delete unreachable_block.first;
	delete unreachable_block.second;
	for (auto obj : static_objects) {
		delete obj.first;
		delete obj.second;
	}
};