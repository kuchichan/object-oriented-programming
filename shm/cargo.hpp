#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBase() const {return basePrice_; }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
