#include "store.hpp"

#include <algorithm>
#include <random>

Store::Store(const std::vector<std::shared_ptr<Cargo>>& stock) : stock_(stock) {}

Store::Store(Time* time) : time_(time) {
    time_->addObserver(this);
}

Store::~Store() {
    time_->removeObserver(this);
}

Store::Response Store::buy(Cargo* cargo, Player* player) {
    if (cargo->getAmount() > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    auto toBuy = findStock(cargo);

    if (toBuy == stock_.end() || (*toBuy)->getAmount() < cargo->getAmount()) {
        return Response::lack_of_cargo;
    }
    if ((*toBuy)->getPrice() > player->getMoney()) {
        return Response::lack_of_money;
    }

    unload(cargo);
    player->loadShip(std::shared_ptr<Cargo>(cargo));
    player->setMoney(player->getMoney() - cargo->getPrice());

    return Response::done;
}

Store::Response Store::sell(Cargo* cargo, Player* player) {
    load(std::shared_ptr<Cargo>(cargo));
    player->unloadShip(cargo);
    player->setMoney(player->getMoney() + cargo->getPrice());

    return Response::done;
}

void Store::load(std::shared_ptr<Cargo> cargo) {
    auto result = findStock(cargo.get());

    if (result == stock_.end()) {
        stock_.push_back(cargo);
        return;
    }
    **result += cargo->getAmount();
}

void Store::unload(Cargo* cargo) {
    auto thing = findStock(cargo);

    if (thing == stock_.end()) {
        return;
    }

    if ((*thing)->getAmount() <= cargo->getAmount()) {
        stock_.erase(thing);
        return;
    }
    **thing -= cargo->getAmount();
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findStock(Cargo* cargo) {
    return std::find_if(stock_.begin(), stock_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });
}

void Store::nextDay() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    std::uniform_int_distribution<> distrib2(0, 20);
    for (const auto& cargo_ptr : stock_) {
        if (distrib(gen)) {
            *cargo_ptr += distrib2(gen);
        } else {
            *cargo_ptr -= distrib2(gen);
        }
    }
}
