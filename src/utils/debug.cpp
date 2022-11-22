
#include "utils/utils.hpp"

namespace utils {

template void printVector(sf::Vector2f);
template void printVector(sf::Vector2i);
template void printVector(sf::Vector2u);

template <typename T>
void printVector(const T pos)
{
    std::cout << "x: " << pos.x << ", y:" << pos.y << std::endl;
}

}
