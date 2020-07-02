#include "locators.hpp"

void TimeServiceLocator::provide(Time* time) {
    time_ = time;
}

Time* TimeServiceLocator::getTime() {
    return time_;
};
