#ifndef COLLISION_H
#define COLLISION_H

#include "PhysicalObject2D.h"
#include "PhysicalMap.h"

bool ComputeMapCollision(PhysicalMap& physmap, PhysicalObject2D& object);

#endif // COLLISION_H