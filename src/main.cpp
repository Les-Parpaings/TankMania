
#include "tankmania.hpp"

using namespace utils;
namespace Tank
{

int main_tankmania(Utils &utils)
{
    TankMania var;
    create_all(var, utils);

    utils.transition.setAnimValue(FADE_OUT);
    while (utils.window.isOpen()) {

        if (utils.transition.getAnimValue() == FADE_OFF)
            get_event_all(var, utils);
        if (utils.transition.getAnimValue() == FADE_DONE)
            break;

        switch (var.part) {
            case PART_MENU:
                break;
            case PART_GAME:
                do_game(var, utils);
                break;
        }

        draw(var, utils);
    }

    destroy_all(var, utils);

    return EXIT_SUCCESS;
}

} // namespace Tank


int main(void)
{
    Utils utils;

    Tank::main_tankmania(utils);

    // int index = 0;
    // int (*func_array[1])(Utils &) = {
    //     Tank::main_tankmania
    // };

    // while (utils.window.isOpen()) {
    //     index = func_array[index](utils);
    // }

    // Pause when debug mode on windows
    #if defined(_WIN32)
        #if defined(_DEBUG)
            system("pause");
        #endif
    #endif

    return EXIT_SUCCESS;
}
