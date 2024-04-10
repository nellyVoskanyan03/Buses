#ifndef CROSSROAD_H
#define CROSSROAD_H

#include <iostream>

class CrossRoad {
public:
    int id;
    int distance;

    CrossRoad(int id, int distance);

    // Declaration of the comparison operator
    bool operator>(const CrossRoad& other) const;
};

#endif // CROSSROAD_H