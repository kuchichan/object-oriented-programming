#pragma once

#include "time.hpp"

class TimeServiceLocator {
public:
    static Time* getTime();
    static void provide(Time* time);

private:
    inline static Time* time_ = nullptr;
};
