#include <alcohol.hpp>
#include "cargo.hpp"
#include "commands.hpp"
#include "player.cpp"
#include "ship.hpp"

int main() {
    auto alco1 = std::make_shared<Alcohol>(Alcohol("Whisky", 0, 100, 47));
    auto alco2 = std::make_shared<Alcohol>(Alcohol("Beer", 10, 12, 8));
    auto alco3 = std::make_shared<Alcohol>(Alcohol("Wine", 0, 40, 47));

    std::unique_ptr<Player> player =
        std::make_unique<Player>(std::make_unique<Ship>(100, 10, 10, player.get()), 100);
    player->loadShip(alco1);
    player->loadShip(alco2);
    player->loadShip(alco3);

    PrintCargo cargoPrinter = PrintCargo();
    cargoPrinter.execute(player.get());

    return 0;
}
