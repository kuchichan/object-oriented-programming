#pragma once

#include "Command.hpp"

class Player;

class PrintCargo : public Command {
public:
    // Overrides from Command
    ~PrintCargo() override = default;
    void execute(Player* player) override;
};
