#include "island.hpp"

Island::Island(int positionX, int positionY) : position_(positionX, positionY) {}

std::ostream & operator<<(std::ostream & stream, const Island& island) {
    stream << "Island coordinates: " << island.getCoordinates();
    return stream;
}
