#pragma once
#include "RenderSnapshot.h"
#include "BoundingShape.h"

class Object {
public:
    virtual RenderSnapshot get_object_snapshot()=0;
    virtual BoundingShape* get_object_bounding_shape() = 0;
};


