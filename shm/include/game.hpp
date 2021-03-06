#pragma once

#include <memory>

#include "sell.hpp"
#include "travel.hpp"
#include "buy.hpp"
#include "map.hpp"
#include "player.hpp"
#include "print_cargo.hpp"
#include "ship.hpp"
#include "time.hpp"

class Game {
public:
    enum class Action {
        Buy = 1,
        Sell,
        Travel,
        PrintCargo,
    };
    Game(size_t money, size_t days, size_t finalGoal);
    void startGame();

private:
    bool checkWinCondition() const;
    bool checkLoseCondition() const;
    void printMenu();
    void printOptions();
    void printWinScreen();
    void printLooseScreen();
    void makeAction(Action action);
    void printCargo();

    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_ = 1;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Travel> travel_command_;
    std::unique_ptr<Buy> buy_command_;
    std::unique_ptr<Sell> sell_command_;
    std::unique_ptr<PrintCargo> print_cargo_command_;
};
