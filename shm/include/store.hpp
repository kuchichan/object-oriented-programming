#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"
#include "time.hpp"

class Store : public Observer {
public:
    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

    Store(const std::vector<std::shared_ptr<Cargo>>& stock, Time* time);
    // override from Observer
    ~Store() override;

    Response buy(Cargo* cargo, Player* player);
    Response sell(Cargo* cargo, Player* player);
    // override from Observer
    void nextDay() override;

private:
    std::vector<std::shared_ptr<Cargo>> stock_;

    void load(std::shared_ptr<Cargo> cargo);
    void unload(Cargo* cargo);
    std::vector<std::shared_ptr<Cargo>>::iterator findStock(Cargo* cargo);
    Time* time_;
};
