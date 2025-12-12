#pragma once
#include "BoundingShapeType.h"
#include "BoundingShape.h"
#include <vec2.hpp> 

class Circle : public BoundingShape {
public:
	glm::vec2 _center;
	float _radius;
	BoundingShapeType get_type() {
		return BoundingShapeType::CIRCLE;
	}
	Circle(int id, glm::vec2 center, float radius) : BoundingShape(id), _center(center), _radius(radius) {};
};