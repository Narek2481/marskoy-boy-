#include <iostream>
#include <cmath>
#include "abstract_player.h"

using namespace std;






class Player_me : public  abstract_player{
public:
};


int  main() {
    srand(time(NULL));
    Player_me x;
    x.generate_ship_coordinates(4);
    x.generate_ship_coordinates(3);
    x.generate_ship_coordinates(3);
    x.generate_ship_coordinates(2);
    x.generate_ship_coordinates(2);
    x.generate_ship_coordinates(2);
    x.generate_ship_coordinates(1);
    x.generate_ship_coordinates(1);
    x.generate_ship_coordinates(1);
    x.generate_ship_coordinates(1);
    x.map_screen();
    return 0;
}