#include "Travel.hpp"

#include <iostream>

#include "TimeServiceLocator.hpp"
#include "map.hpp"
#include "player.hpp"

Travel::Travel(Map* map, Time* time)
    : map_(map), time_(time) {}

void Travel::execute(Player* player) {
    std::cout << "Your current position: " << map_->getCurrentPosition()->getCoordinates() << "\n";
    displayPossibleOptions();
    std::cout << "Enter the coordinates of the chosen island: ";
    int coordinate_x = 0, coordinate_y = 0;
    std::cin >> coordinate_x >> coordinate_y;
    while (!map_->getIsland(Coordinates(coordinate_x, coordinate_y))) {
        enterCoordinatesAgain(coordinate_x, coordinate_y);
    }
    auto daysOfTravel = countDaysOfTravel(player, coordinate_x, coordinate_y);
    incrementDays(daysOfTravel);
    map_->travel(map_->getIsland(Coordinates(coordinate_x, coordinate_y)));
    std::cout << "Time of travel: " << daysOfTravel << "\n";
}

void Travel::displayPossibleOptions() {
    for (auto elem : map_->getAllIslands()) {
        if (elem.getCoordinates() == map_->getCurrentPosition()->getCoordinates()) {
            continue;
        }
        std::cout << elem << "\n";
    }
}

void Travel::enterCoordinatesAgain(int& x, int& y) {
    std::cout << "Wrong coordinates!\n";
    std::cout << "Enter new coordinates: ";
    std::cin >> x >> y;
}

void Travel::incrementDays(size_t count) {
    for (size_t i = 0; i < count; ++i) {
        TimeServiceLocator::getTime()->operator++();
    }
}

size_t Travel::countDaysOfTravel(Player* player, int coordinate_x, int coordinate_y) {
    return map_->getDistanceToIsland(map_->getIsland(Coordinates(coordinate_x, coordinate_y))) / player->getSpeed();
}
