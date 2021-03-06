#include "alcohol.hpp"

#include <algorithm>
#include <typeinfo>

Alcohol::Alcohol(const std::string& name,
                 size_t amount,
                 size_t basePrice,
                 size_t percentage)
    : Cargo(name, amount, basePrice), percentage_(percentage) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(percentage_)) / maxPercentage_);
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    (amount_ <= amount) ? amount_ = 0 : amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& other) const {
    if (typeid(*this).hash_code() != typeid(other).hash_code()) {
        return false;
    }
    return (amount_ == other.getAmount() && basePrice_ == other.getBasePrice() &&
            name_ == other.getName() && getPrice() == other.getPrice());
}
