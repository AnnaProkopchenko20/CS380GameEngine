#pragma once
#include <map>
#include<functional>
#include "BoundingShapeType.h"
#include "BoundingShape.h"
#include "CollisionAlgorithms.h"

class CollisionTable {

	inline static std::map<std::pair<BoundingShapeType, BoundingShapeType>, std::function<bool(BoundingShape*, BoundingShape*)>> table;

public:

	CollisionTable() {
		table.emplace(
			std::make_pair(BoundingShapeType::CIRCLE, BoundingShapeType::CIRCLE),
			[](const BoundingShape* a, const BoundingShape* b) {return CollisionAlgorithms::circle_and_circle_collision(a, b); }
		);

		table.emplace(
			std::make_pair(BoundingShapeType::CIRCLE, BoundingShapeType::AABB),
			[](const BoundingShape* a, const BoundingShape* b) {return CollisionAlgorithms::circle_and_aabb_collision(a, b); }
		);

		table.emplace(
			std::make_pair(BoundingShapeType::AABB, BoundingShapeType::AABB),
			[](const BoundingShape* a, const BoundingShape* b) {return CollisionAlgorithms::aabb_and_aabb_collision(a, b); }
		);

	}

	bool check_collision(BoundingShape* a, BoundingShape* b) {

		BoundingShapeType id_a = a->get_type();
		BoundingShapeType id_b = b->get_type();

		if (id_a > id_b) {

			return table.at(std::make_pair(id_b, id_a))(b, a);
		}

		return table.at({ id_a, id_b })(a, b);
	}

};



