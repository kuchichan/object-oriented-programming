#pragma once

#include <memory>

#include "Command.hpp"

class Buy;
class Travel;
class Map;
class Player;
class PrintCargo;
class Sell;
class Ship;
class Time;

class Game {
public:
    enum class Action {
        Buy,
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
    std::unique_ptr<Map> map_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Travel> travel_command_;
    std::unique_ptr<Buy> buy_command_;
    std::unique_ptr<Sell> sell_command_;
    std::unique_ptr<PrintCargo> print_cargo_command_;
};
