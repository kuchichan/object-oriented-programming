#pragma once

#include "coordinates.hpp"
#include "store.hpp"

class Island {
public:
    Island(int positionX, int positionY);
    Coordinates getCoordinates() const { return position_; }

private:
    Coordinates position_;
};
