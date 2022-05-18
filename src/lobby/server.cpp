
#include "tank.hpp"

//Initialize listener for host player
void server(all_t &var)
{
    var.network.listener.listen(2000);
    var.network.listener.accept(var.network.socket);
}
