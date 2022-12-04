
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

template void printRect(sf::IntRect);
template void printRect(sf::FloatRect);

template <typename T>
void printRect(const T rect)
{
    std::cout << "left: " << rect.left << ", top:" << rect.top << ", width:" << rect.width << ", height:" << rect.height << std::endl;
}

void printJoystick(int index)
{
    if (sf::Joystick::isConnected(index)) {
        std::vector<std::string> axes = {"X", "Y", "Z", "R", "U", "V", "PovX", "PovY"};

        std::cout << "Button count: " << sf::Joystick::getButtonCount(index) << std::endl;
        for (size_t i = 0; i < axes.size(); i++) {
            std::cout << "Axis " << axes[i] << ":\t" << ((sf::Joystick::hasAxis(index, sf::Joystick::Axis(i))) ? "supported" : "not supported") << std::endl;
        }
        std::cout << "ID name: " << sf::Joystick::getIdentification(index).name.toAnsiString() << std::endl;
        std::cout << "ID product: " << sf::Joystick::getIdentification(index).productId << std::endl;
        std::cout << "ID vendor: " << sf::Joystick::getIdentification(index).vendorId << std::endl;
    }
}

}
