
#include "TimeServiceLocator.hpp"
#include "time.hpp"

std::unique_ptr<Time> TimeServiceLocator::time_ = std::make_unique<Time>(Time());

// void TimeServiceLocator::provide(Time* time) {
//     time_ = time;
// }

Time* TimeServiceLocator::getTime() {
    return time_.get();
};
