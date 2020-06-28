#pragma once

#include <cstddef>

class Game {
public:
    Game(size_t start_money, size_t game_days, size_t final_goal);

private:
    const size_t start_money_;
    const size_t game_days_;
    const size_t final_goal_;
};
