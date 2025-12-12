#pragma once
#include "CollisionTable.h"
#include <array>

class SpatialGrid {
	static const int horizontal_cell_count = 12;
	static const int vertical_cell_count = 12;
	float cell_width;
	float cell_height;
	std::array< std::array<std::vector<int>, vertical_cell_count>, horizontal_cell_count > grid = {};

public:
	SpatialGrid() {
		cell_width = GameSettings::screen_width_px / horizontal_cell_count;
		cell_height = GameSettings::screen_height_px / vertical_cell_count;
	};
	void clear() {
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell.clear();
			}
		}
	};
	void fill(std::vector<BoundingShape*>& bounding_shapes, CollisionTable& table) {
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {

				auto cell_aabb = AABBShape(1, glm::vec2(cell_width * i, cell_height * j), glm::vec2(cell_width, cell_height));
				for (auto& bounding_shape : bounding_shapes) {
					if (table.check_collision(&cell_aabb, bounding_shape)) {
						grid[i][j].push_back(bounding_shape->_id);
					}
				}
			}
		}
	};

	std::map<std::pair<int, int>, bool> get_potential_collision_pairs(std::map<std::pair<int, int>, bool> interested_results) {

		for (const auto& row : grid) {
			for (const auto& cell : row) {
				if (cell.size() > 1) {
					for (size_t i = 0; i < cell.size(); ++i) {
						for (size_t j = i + 1; j < cell.size(); ++j) {
							if (cell.at(i) > cell.at(j)) {
								interested_results[{cell.at(j), cell.at(i) }] = true;
							}
							interested_results[{cell.at(i), cell.at(j) }] = true;
						}
					}
				}
			}
		}
		return interested_results;
	};

};
