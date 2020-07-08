#include "commands.hpp"
#include <iostream>
Buy::Buy(Map* map) : map_(map) {}

void Buy::execute(Player* player) {
    while (true) {
        auto store = map_->getCurrentPosition()->getStore();
        std::cout << "\n" << *store.get() << "\n";

        size_t position{};
        size_t quantity{};

        std::cout
            << "Please enter the position and amount of cargo you are interested in";
        std::cin >> position >> quantity;
        if (quantity == 0) {
        }
        Cargo* cargo = store->getCargo(position);
        if (!cargo) {
            std::cout << "Wrong position or cargo does not exist";
            continue;
        }

        char answer = 'y';
        while (true) {
            std::cout << "The price is " << cargo->getPrice() * quantity
                      << "Are you sure want to buy it? [y/ other key]";
            std::cin >> answer;
            if (std::tolower(answer) == 'y') {
                break;
            } else {
                return;
            }
        }

        switch (store->buy(cargo, quantity, player)) {
        case Store::Response::done:
            std::cout << "Good one! You have bought " << cargo << " in quantity "
                      << quantity << "\n";
            return;

        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money!";
            break;
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space!";
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "Store does not have as much cargo as you need!";
            break;
        }
    }
}

Sell::Sell(Map* map) : map_(map) {}
Travel::Travel(Map* map, Time* time) : map_(map), time_(time) {}
