#pragma once

#include "map.hpp"
#include "player.hpp"

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute(Player* player) = 0;
};

class Sell : public ICommand {
public:
    Sell(Map* map);

    // Overrides from Icommand
    ~Sell() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
};
