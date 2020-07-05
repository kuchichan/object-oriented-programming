#pragma once

#include <memory>
class Time;

class TimeServiceLocator {
public:
    static Time* getTime();
    // static void provide(Time* time);

private:
    static std::unique_ptr<Time> time_;
};
