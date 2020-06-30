#pragma once

#include <cstddef>

class Game {
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);

private:
    size_t money_;
    const size_t gameDays_;
    const size_t finalGoal_;

    bool checkWinCondition() const;
    bool checkLoseCondition() const;
};
