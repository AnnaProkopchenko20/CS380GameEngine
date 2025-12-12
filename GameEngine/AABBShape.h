#pragma once
#include "BoundingShapeType.h"
#include "BoundingShape.h"
#include <vec2.hpp> 

class AABBShape : public BoundingShape {
public:
	glm::vec2 _size;
	glm::vec2 _pos;
	BoundingShapeType get_type() {
		return BoundingShapeType::AABB;
	}
	AABBShape(int id, glm::vec2 size, glm::vec2 pos) : BoundingShape(id), _size(size), _pos(pos) {};
};