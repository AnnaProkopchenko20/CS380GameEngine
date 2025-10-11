#pragma once
#include "ObjectSnapshot.h"

class Object {
public:
    virtual ObjectSnapshot get_object_snapshot()=0;
};


