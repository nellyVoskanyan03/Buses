#include "crossroad.h"

CrossRoad::CrossRoad(int id, int distance) : id(id), distance(distance) {}

// Definition of the comparison operator
bool CrossRoad::operator>(const CrossRoad& other) const {
    return distance > other.distance;
}