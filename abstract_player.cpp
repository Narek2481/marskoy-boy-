#ifndef ABSTRACT_PLAYER
#define ABSTRACT_PLAYER
#include <iostream>
#include <cmath>
#include "abstract_player.h"
using namespace std;


void abstract_player::generate_ship_coordinates(int size){
    int x = rand()%10;
    int y = rand()%10;
    while (ships[x][y] != 0) {
        x = rand()%10;
        y = rand()%10;
    }
    switch (size) {
        case 1: {
            ships[x][y] = 1;
            circle_close(x,y);
            break;
        }
        case 2: generate_ship_coordinates_second(x,y,ships); break;
        case 3: generate_ship_coordinates_thirds(x,y,ships); break;
        case 4: generate_ship_coordinates_quarters(x,y,ships); break;
        default: break;
    }
};

void abstract_player::map_screen(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(ships[i][j]== 0) {
                cout << "-  ";
            }else if(ships[i][j]== -2) {
                cout << "*  ";
            }else if(ships[i][j]== -1) {
                cout << "X  ";
            }
            else{
                cout << ships[i][j] << "  ";
            }
        }
        cout << endl;
    }
};

void abstract_player::generate_ship_coordinates_quarters(int x,int y,int ships[][10] ){
    ships[x][y] = 4;
    bool check = true;
    while(check){
        int random_parties = rand()%4;
        switch (random_parties) {
        case 0:
            if(x + 3 < 10 && x + 3 > -1 &&ships[x+3][y] == 0 ) {
                ships[x+3][y] = 4;
                ships[x+2][y] = 4;
                ships[x+1][y] = 4;
                circle_close(x+3,y);
                circle_close(x+2,y);
                circle_close(x+1,y);
                check = false;
            }
            break;
        case 1:
            if(x - 3 > -1  && x - 3 < 10  && ships[x-3][y] == 0 ) {
                ships[x-3][y] = 4;
                ships[x-2][y] = 4;
                ships[x-1][y] = 4;

                circle_close(x-3,y);
                circle_close(x-2,y);
                circle_close(x-1,y);
                check = false;
            }
            break;
        case 2:
            if(y + 3 < 10 && y + 3 > -1 && ships[x][y+3] == 0 ) {
                ships[x][y+3] = 4;
                ships[x][y+2] = 4;
                ships[x][y+1] = 4;

                circle_close(x,y+3);
                circle_close(x,y+2);
                circle_close(x,y+1);
                check = false;
            }
            break;
        case 3:
            if(y - 3 > -1 && y - 3 < 10 &&ships[x][y+3] == 0 ) {
                ships[x][y-3] = 4;
                ships[x][y-2] = 4;
                ships[x][y-1] = 4;

                circle_close(x,y-3);
                circle_close(x,y-2);
                circle_close(x,y-1);
                check = false;
            }
            break;
        default: break;
        }
    }
    circle_close(x,y);
};

void abstract_player::generate_ship_coordinates_thirds(int x,int y,int ships[][10]){
    ships[x][y] = 3;
    bool check = true;
    while(check){
        int random_parties = rand()%4;
        switch (random_parties)
        {
        case 0:
            if(x + 2 < 10 && x + 2 > -1 && ships[x+2][y] == 0 ) {
                ships[x+2][y] = 3;
                ships[x+1][y] = 3;
                circle_close(x+2,y);
                circle_close(x+1,y);
                check = false;
            }
            break;
        case 1:
            if(x - 2 > -1  && x - 2 < 10  && ships[x-2][y] == 0 ) {
                ships[x-2][y] = 3;
                ships[x-1][y] = 3;
                circle_close(x-2,y);
                circle_close(x-1,y);
                check = false;
            }
            break;
        case 2:
            if(y + 2 < 10 && y + 2 > -1 && ships[x][y+2] == 0 ) {
                ships[x][y+2] = 3;
                ships[x][y+1] = 3;
                circle_close(x,y+2);
                circle_close(x,y+1);
                check = false;
            }
            break;
        case 3:
            if(y - 2 > -1 && y - 2 < 10 && ships[x][y+2] == 0 ) {
                ships[x][y-2] = 3;
                ships[x][y-1] = 3;
                circle_close(x,y-2);
                circle_close(x,y-1);
                check = false;
            }
            break;
        default: break;
        }
    }
    circle_close(x,y);
};

void abstract_player::generate_ship_coordinates_second(int x,int y,int ships[][10]){
    ships[x][y] = 2;
    bool check = true;
    while(check){
        int random_parties = rand()%4;
        switch (random_parties)
        {
            case 0:
                // circle_close(x+1, y);
                // check = false;
                if(x + 1 < 10 && x + 1 > -1 && ships[x+1][y] == 0 ) {
                    ships[x+1][y] = 2;
                    circle_close(x+1, y);
                    check = false;
                }
                break;
            case 1:
                if(x - 1 > -1  && x - 1 < 10  && ships[x-1][y] == 0 ) {
                    ships[x-1][y] = 2;
                    circle_close(x-1, y);
                    check = false;
                }
                break;
            case 2:
                if(y + 1 < 10 && y + 1 > -1 && ships[x][y+1] == 0 ) {
                    ships[x][y+1] = 2;
                    circle_close(x, y+1);
                    check = false;
                }
                break;
            case 3:
                if(y - 1 > -1 && y - 1 < 10 && ships[x][y+1] == 0 ) {
                    ships[x][y-1] = 2;
                    circle_close(x, y-1);
                    check = false;
                }
                break;
            default: break;
        }
    }
    circle_close(x,y);
};

void abstract_player::circle_close(int x, int y) {
    if(y - 1 < 10 && y - 1 > -1) setEmptyValue(x, y - 1);
    if(y + 1 < 10 && y + 1 > -1) setEmptyValue(x, y + 1);
    if(x - 1 < 10 && x - 1 > -1) setEmptyValue(x - 1, y);
    if(x + 1 < 10 && x + 1 > -1) setEmptyValue(x + 1, y);

    if(y - 1 < 10 && y - 1 > -1 && x - 1 < 10 && x - 1 > -1) setEmptyValue(x - 1, y - 1);
    if(y + 1 < 10 && y + 1 > -1 && x + 1 < 10 && x + 1 > -1) setEmptyValue(x + 1, y + 1);
    if(y + 1 < 10 && y + 1 > -1 && x - 1 < 10 && x - 1 > -1) setEmptyValue(x - 1, y + 1);
    if(y - 1 < 10 && y - 1 > -1 && x + 1 < 10 && x + 1 > -1) setEmptyValue(x + 1, y - 1);
};

void abstract_player::setEmptyValue(int x, int y) {
    if (0 == ships[x][y]) {
        ships[x][y] = 5;
    }
}
#endif