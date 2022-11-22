
#include "utils/random.hpp"
#include <bitset>
#include <random>
#include <iostream>

namespace Random
{

template signed char        getRandom<signed char>                  (signed char);
template signed short       getRandom<signed short>                 (signed short);
template signed int         getRandom<signed int>                   (signed int);
template signed long long   getRandom<signed long long>             (signed long long);
template unsigned char      getRandom<unsigned char>                (unsigned char);
template unsigned short     getRandom<unsigned short>               (unsigned short);
template unsigned int       getRandom<unsigned int>                 (unsigned int);
template unsigned long long getRandom<unsigned long long>           (unsigned long long);

template signed char        getRandomInRange<signed char>           (signed char,           signed char);
template signed short       getRandomInRange<signed short>          (signed short,          signed short);
template signed int         getRandomInRange<signed int>            (signed int,            signed int);
template signed long long   getRandomInRange<signed long long>      (signed long long,      signed long long);
template unsigned char      getRandomInRange<unsigned char>         (unsigned char,         unsigned char);
template unsigned short     getRandomInRange<unsigned short>        (unsigned short,        unsigned short);
template unsigned int       getRandomInRange<unsigned int>          (unsigned int,          unsigned int);
template unsigned long long getRandomInRange<unsigned long long>    (unsigned long long,    unsigned long long);

template <typename T>
T get_max_value_of_type(T limit)
{
    int size = sizeof(limit) * 8;

    limit = 0;
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            T check = limit;
            check <<= 1;
            if (check < 0) {
                break;
            }
        }
        limit <<= 1;
        limit++;
    }
    return limit;
}

template <typename T>
T getRandom(T max)
{
    T limit = 0;
    limit = get_max_value_of_type(limit);

    T nbr = max + 1;
    while (nbr > max) {

        nbr = 0;
        for (int i = (sizeof(max) * 8) / 16; i > 1; i--) {
            nbr += ((std::rand()) << (i - 1) * 16);
        }
        nbr += std::rand() + std::rand();
        nbr = nbr / ((unsigned)(limit) / max);
    }

    if (nbr == max)
        nbr--;

    return nbr;
}

template <typename T>
T getRandomInRange(T min, T max)
{
    if (min == max)
        return min;

    T limit = 0;
    limit = get_max_value_of_type(limit);

    T diff = max - min;
    T nbr = diff + 1;
    while (nbr > diff) {

        nbr = 0;
        for (int i = (sizeof(max) * 8) / 16; i > 1; i--) {
            nbr += ((std::rand()) << (i - 1) * 16);
        }
        nbr += std::rand() + std::rand();
        nbr = nbr / ((unsigned)(limit) / diff);
    }

    return nbr + min;
}

} // namespace Random
