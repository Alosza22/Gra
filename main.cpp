#include "Gra.h"

int main()
{
    srand(time(NULL));
    menu();

    while(!player_dead)
    {
        gra();
    }
    return 0;
}
