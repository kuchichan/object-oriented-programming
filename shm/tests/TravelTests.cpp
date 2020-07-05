#include "gtest/gtest.h"
#include "Command.hpp"
#include "map.hpp"
#include "TimeServiceLocator.hpp"
#include "Travel.hpp"
#include "player.hpp"

class TravelCommandTest :public ::testing::Test {
    public:
    Player player;
    Map map;
    Travel travel;
    TravelCommandTest()
    : player(100),
    map(),
    travel(&map, TimeServiceLocator::getTime()) {}
};

TEST_F(TravelCommandTest, TravelToYourCurrentPositionShouldNotChangeElapsedTime) {
    auto timeBeforeTravel = TimeServiceLocator::getTime()->getElapsedTime();
    map.travel(map.getCurrentPosition());
    auto timeAfterTravel = TimeServiceLocator::getTime()->getElapsedTime();
    ASSERT_EQ(timeBeforeTravel, timeAfterTravel);
}
