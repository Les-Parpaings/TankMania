
#include "tankmania.hpp"

using namespace utils;

int main(void)
{
    Utils utils;
    Tank::Settings settings;

    int index = 0;
    int (*func_array[1])(Utils &, Tank::Settings &) = {
        Tank::main_game
    };

    while (utils.window.isOpen()) {
        index = func_array[index](utils, settings);
    }

    // Pause when debug mode on windows
    #if defined(_WIN32)
        #if defined(_DEBUG)
            system("pause");
        #endif
    #endif

    return EXIT_SUCCESS;
}
