#include "game.hpp"

#include <iostream>

#include "TimeServiceLocator.hpp"

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money),
      days_(days),
      final_goal_(final_goal),
      time_(std::make_unique<Time>()) {
    map_ = std::make_unique<Map>();

    player_ = std::make_unique<Player>(
        std::make_unique<Ship>(10, 10, 10, player_.get()), money);
    travel_command_ = std::make_unique<Travel>(map_.get(), TimeServiceLocator::getTime());
}

void Game::makeAction(Action action) {
    switch (action) {
    case Action::Travel:
        travel_command_->execute(player_.get());
        break;
    default:
        std::cout << "Bad command"
                  << "\n";
    }
}

bool Game::checkWinCondition() const {
    return money_ >= final_goal_;
}

bool Game::checkLoseCondition() const {
    return money_ == 0 || (current_day_ >= days_ && money_ < final_goal_);
}
