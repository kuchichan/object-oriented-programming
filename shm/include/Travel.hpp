#pragma once

#include "Command.hpp"
#include <cstddef>

class Map;
class Time;

class Travel : public Command {
public:
    Travel(Map* map, Time* time);

    // Overrides from Command
    ~Travel() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
    Time* time_;

    void displayPossibleOptions();
    void enterCoordinatesAgain(int & x, int & y);
    size_t countDaysOfTravel(Player* player, int coordinate_x, int coordinate_y);
    void incrementDays(size_t count);
};
