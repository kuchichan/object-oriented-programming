#include "game.hpp"

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money), gameDays_(gameDays), finalGoal_(finalGoal) {}

bool Game::checkWinCondition() const {
    return money_ >= finalGoal_;
}

bool Game::checkLoseCondition() const {
    return money_ <= 0;
}
