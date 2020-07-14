#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinate);
    Island* getCurrentPosition() const { return currentPosition_; };
    const std::vector<Island>& getAllIslands() { return Islands_; };
    size_t getDistanceToIsland(Island* destination);
    void travel(Island* destination);


private:
    std::vector<Island> Islands_;
    Island* currentPosition_;
};
