#pragma once
#include "RenderSnapshot.h"

class Object {
public:
    virtual RenderSnapshot get_object_snapshot()=0;
};


