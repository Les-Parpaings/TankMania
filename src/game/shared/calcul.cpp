
#include "game/main.hpp"

using namespace utils;
namespace Tank {

float calculMove(float angle, float velocity)
{
    float value = angle;
    bool reverse = false;

    // Y case, if it exceed 360°
    if (value >= 360.0f)
        value -= 360.0f;

    // If angle is in the negative part
    if (value > 180.0f) {
        value -= 180.0f;
        reverse = true;
    }

    if (value > 90.0f)
        value = 180.0f - value;
    value /= (90.0f / velocity);

    if (reverse)
        value = -value;

    return value;
}

}
