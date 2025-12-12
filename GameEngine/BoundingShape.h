#pragma once
#include "BoundingShapeType.h"

class BoundingShape {
public:
	int _id;
	virtual BoundingShapeType get_type() = 0;
	BoundingShape(int id) : _id(id) {};
};