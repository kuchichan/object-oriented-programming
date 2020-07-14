#pragma once

#include <memory>

#include "Command.hpp"

class Map;
class Player;
class Store;

class Buy : public Command {
public:
    Buy(Map* map);

    // Overrides from Command
    ~Buy() override = default;
    void execute(Player* player) override;
    void displayStore(std::shared_ptr<Store> store);

private:
    Map* map_;
};
