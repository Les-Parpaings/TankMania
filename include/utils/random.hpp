
#pragma once

#include <random>
#include <chrono>

namespace Random {

/// \brief Generate a random number between 0 and max - 1. 0 <= nbr < max
/// \param max
/// \tparam char
/// \tparam short
/// \tparam int
/// \tparam long_long
/// \return number generated
template <typename T>
T getRandom(T max)
{
    if (max <= 0)
        return 0;

    std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> distribution(0, max - 1);

    T nbr = (T)distribution(gen);
    if (nbr >= max)
        nbr = max - 1;

    return nbr;
}
/// \brief Generate a random number between min and max. min <= nbr < max
/// \param min
/// \param max
/// \tparam char
/// \tparam short
/// \tparam int
/// \tparam long long
/// \return number generated
template <typename T>
T getRandomInRange(T min, T max)
{
    if (max <= min)
        return min;

    std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> distribution(min, max);

    T nbr = (T)distribution(gen);
    if (nbr >= max)
        nbr = max - 1;

    return nbr;
}

}; // namespace utils
