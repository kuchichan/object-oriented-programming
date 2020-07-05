#pragma once

#include "coordinates.hpp"

class Island {
public:
    Island(int positionX, int positionY);
    Coordinates getCoordinates() const { return position_; }
    friend std::ostream & operator<<(std::ostream & stream, const Island& island);


private:
    Coordinates position_;
};
