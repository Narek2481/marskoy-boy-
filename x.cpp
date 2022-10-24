#include <iostream>
#include <cmath>


using namespace std;



// void paint_ship(int x,int y,int x_end,int y_end,bool is_x,int arr_vessel[][10],int ship_size){
//     cout<< 3 << endl;
//     if(is_x == true){
//         for (int i = y; i <= y_end; i++)
//         {
//             arr_vessel[x][i] = ship_size;
//         }
//         for (int i = y; i <= y_end; i++)
//         {
//             circle_close(arr_vessel,i,y);
//         }
//     }else{
//         for (int i = x; i <= x_end; i++)
//         {
//             arr_vessel[i][y] = ship_size;
//         }
//         for (int i = x; i <= x_end; i++)
//         {
//             circle_close(arr_vessel,i,y);
//         }
//     }
// }

// void chack_ship_way (int arr_vessel[][10],int enpty_fileds[][2],int x,int y,int ship_size){

//     int enpty_fileds_rand = rand() % 4;
//     bool is_x;
//     if(enpty_fileds[enpty_fileds_rand][0] < 10 && enpty_fileds[enpty_fileds_rand][0] > -1){
//         if(enpty_fileds[enpty_fileds_rand][0] == x){
//             if(x < enpty_fileds[enpty_fileds_rand][0] ){
//             for (int i = x; i <= enpty_fileds[enpty_fileds_rand][1]; i++)
//             {
//                 if(!(arr_vessel[x][i] == 0)){
//                     enpty_fileds[enpty_fileds_rand][0] == 10;
//                     chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//                 }
//             }
//             is_x = true;
//             if(y > enpty_fileds[enpty_fileds_rand][1]){
//                 paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
//             }else{
//                 paint_ship(x,enpty_fileds[enpty_fileds_rand][1],x,y,is_x,arr_vessel,ship_size);
//             }
//             }else{
//                 for (int i = enpty_fileds[enpty_fileds_rand][1]; i <= x; i++)
//             {
//                 if(!(arr_vessel[x][i] == 0)){
//                     enpty_fileds[enpty_fileds_rand][0] == 10;
//                     chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//                 }
//             }
//             is_x = true;
//             if(y > enpty_fileds[enpty_fileds_rand][1]){
//                 paint_ship(x,enpty_fileds[enpty_fileds_rand][1],x,y,is_x,arr_vessel,ship_size);
//             }else{
//                 paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
//             }
//             }
//         }else if(enpty_fileds[enpty_fileds_rand][1] == y){
//             if(y < enpty_fileds[enpty_fileds_rand][0]){
//             for (int i = y; i <= enpty_fileds[enpty_fileds_rand][0]; i++)
//             {
//                 if(!(arr_vessel[i][y] == 0)){
//                     enpty_fileds[enpty_fileds_rand][1] == 10;
//                     chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//                 }
//             }
//             is_x = false;
//             if(y > enpty_fileds[enpty_fileds_rand][1]){
//                 paint_ship(enpty_fileds[enpty_fileds_rand][0],y,x,y,is_x,arr_vessel,ship_size);
//             }else{
//                 paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
//             }
//             }else{
//                 for (int i = enpty_fileds[enpty_fileds_rand][0]; i <= y; i++)
//             {
//                 if(!(arr_vessel[i][y] == 0)){
//                     enpty_fileds[enpty_fileds_rand][1] == 10;
//                     chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//                 }
//             }
//             is_x = false;
//             if(y > enpty_fileds[enpty_fileds_rand][1]){
//                 paint_ship(enpty_fileds[enpty_fileds_rand][0],y,x,y,is_x,arr_vessel,ship_size);
//             }else{
//                 paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
//             }
//             }
//         }else{
//              chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//         }
//     }else{
//         chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//     }
// }

// void ship_random_all(int arr_vessel[][10],const int size,int ship_size){

//     int x = rand()%10;
//     int y = rand()%10;
//     if(arr_vessel[x][y] == 0){
//         int enpty_fileds [4][2]{
//             {10,10},
//             {10,10},
//             {10,10},
//             {10,10}
//         };
//         if(x+ship_size-1 < 10 && x+ship_size-1 > -1 && arr_vessel[x+ship_size-1][y] == 0){
//             enpty_fileds[0][0] = x+ship_size-1;
//             enpty_fileds[0][1] = y;
//         }
//         if(y+ship_size-1 < 10 && y+ship_size-1 > -1 && arr_vessel[x][y+ship_size-1] == 0){
//             enpty_fileds[1][1] = y+ship_size-1;
//             enpty_fileds[1][0] = x;

//         }
//         if(x-(ship_size-1) < 10 && x-(ship_size-1) > -1 && arr_vessel[x-(ship_size-1)][y] == 0){
//             enpty_fileds[2][0] = x-(ship_size-1);
//             enpty_fileds[2][1] = y;
//         }
//         if(y-(ship_size-1) < 10 && y-(ship_size-1) > -1 && arr_vessel[x][y-(ship_size-1)] == 0){
//             enpty_fileds[3][1] = y-(ship_size-1);
//             enpty_fileds[3][0] = x;
//         }
//         chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
//     }else{
//         ship_random_all(arr_vessel,size,ship_size);
//     }
// }

class Player_me {
public:
    void circle_close(int x, int y) {
        if(y - 1 < 10 && y - 1 > -1){
            if(ships[x][y - 1] == 0){
                ships[x][y - 1] = 5;
            }
        }
        if(y + 1 < 10 && y + 1 > -1){
            if(ships[x][y + 1] == 0){
                ships[x][y + 1] = 5;
            }
        }
        if(x - 1 < 10 && x - 1 > -1){
            if(ships[x - 1][y] == 0){
                ships[x - 1][y] = 5;
            }
        }
        if(x + 1 < 10 && x + 1 > -1){
            if( ships[x + 1][y] == 0){
                ships[x + 1][y] = 5;
            }
        }
        if(y - 1 < 10 && y - 1 > -1 && x - 1 < 10 && x - 1 > -1){
            if( ships[x - 1][y - 1] == 0){
                ships[x - 1][y - 1] = 5;
            }
        }
        if(y + 1 < 10 && y + 1 > -1 && x + 1 < 10 && x + 1 > -1){
            if(ships[x + 1][y + 1] == 0){
                ships[x + 1][y + 1] = 5;
            }
        }
        if(y + 1 < 10 && y + 1 > -1 && x - 1 < 10 && x - 1 > -1){
            if(ships[x - 1][y + 1] == 0){
                ships[x - 1][y + 1] = 5;
            }
        }
        if(y - 1 < 10 && y - 1 > -1 && x + 1 < 10 && x + 1 > -1){
            if(ships[x + 1][y - 1] == 0){
                ships[x + 1][y - 1] = 5;
            }
        }
    }


    void generate_ship_coordinates(int size){
        int x = rand()%10;
        int y = rand()%10;
        while (ships[x][y] != 0) {
            x = rand()%10;
            y = rand()%10;
        }
        switch (size)
        {
        case 1:
            ships[x][y] = 1;
            circle_close(x,y);
            break;
        case 2:
            generate_ship_coordinates_second(x,y,ships);
            break;
        case 3:
            generate_ship_coordinates_thirds(x,y,ships);
            break;
        case 4:
            generate_ship_coordinates_quarters(x,y,ships);
            break;
        default:
            break;
        }
    }

    // void generate_double_ship(int x,int y ){
    //     int k = rand()%4;
    // }

    void map_screen(){
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(ships[i][j]==0){
                    cout << "-  ";
                }else{
                    cout << ships[i][j] << "  ";
                }
            }
            cout << endl;
        }
    }
private:
    int ships[10][10]{
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    void generate_ship_coordinates_quarters(int x,int y,int ships[][10] ){
        ships[x][y] = 4;
        bool check = true;
        while(check){
            int random_parties = rand()%4;
            switch (random_parties)
            {
            case 0:
                if(x + 3 < 10 && x + 3 > -1 &&ships[x+3][y] == 0 ){
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
                if(x - 3 > -1  && x - 3 < 10  && ships[x-3][y] == 0 ){
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
                if(y + 3 < 10 && y + 3 > -1 && ships[x][y+3] == 0 ){
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
                if(y - 3 > -1 && y - 3 < 10 &&ships[x][y+3] == 0 ){
                    ships[x][y-3] = 4;
                    ships[x][y-2] = 4;
                    ships[x][y-1] = 4;

                    circle_close(x,y-3);
                    circle_close(x,y-2);
                    circle_close(x,y-1);
                    check = false;
                }
                break;
            default:

                break;
            }
        }   
        
        circle_close(x,y);
    }
    void generate_ship_coordinates_thirds(int x,int y,int ships[][10]){
        ships[x][y] = 3;
        bool check = true;
        while(check){
            int random_parties = rand()%4;
            switch (random_parties)
            {
            case 0:
                if(x + 2 < 10 && x + 2 > -1 && ships[x+2][y] == 0 ){
                    ships[x+2][y] = 3;
                    ships[x+1][y] = 3;
                    circle_close(x+2,y);
                    circle_close(x+1,y);
                    check = false;
                }
                break;
             case 1:
                if(x - 2 > -1  && x - 2 < 10  && ships[x-2][y] == 0 ){
                    ships[x-2][y] = 3;
                    ships[x-1][y] = 3;
                    circle_close(x-2,y);
                    circle_close(x-1,y);
                    check = false;
                }
                break;
            case 2:
                if(y + 2 < 10 && y + 2 > -1 && ships[x][y+2] == 0 ){
                    ships[x][y+2] = 3;
                    ships[x][y+1] = 3;
                    circle_close(x,y+2);
                    circle_close(x,y+1);
                    check = false;
                }
                break;
            case 3:
                if(y - 2 > -1 && y - 2 < 10 && ships[x][y+2] == 0 ){
                    ships[x][y-2] = 3;
                    ships[x][y-1] = 3;
                    circle_close(x,y-2);
                    circle_close(x,y-1);
                    check = false;
                }
                break;
            default:
                break;
            }
        }   
        circle_close(x,y);
    }
    void generate_ship_coordinates_second(int x,int y,int ships[][10]){
        ships[x][y] = 2;
        bool check = true;
        while(check){
            int random_parties = rand()%4;
            switch (random_parties)
            {
            case 0:
                if(x + 1 < 10 && x + 1 > -1 && ships[x+1][y] == 0 ){
                   ships[x+1][y] = 2;
                    circle_close(x+1,y);
                    check = false;
                }
                break;
             case 1:
                if(x - 1 > -1  && x - 1 < 10  && ships[x-1][y] == 0 ){
                    ships[x-1][y] = 2;
                    circle_close(x-1,y);
                    check = false;
                }
                break;
            case 2:
                if(y + 1 < 10 && y + 1 > -1 && ships[x][y+1] == 0 ){
                    ships[x][y+1] = 2;
                    circle_close(x,y+1);
                    check = false;
                }
                break;
            case 3:
                if(y - 1 > -1 && y - 1 < 10 && ships[x][y+1] == 0 ){
                    ships[x][y-1] = 2;
                    circle_close(x,y-1);
                    check = false;
                }
                break;
            default:
                break;
            }
        }   
        
        circle_close(x,y);
    }
};


int  main() {
    srand(time(NULL));
	// const  int size = 10; // dashti erkararutyuny ev laynutyunt ev naveri qanaky
	// int arr_vessel[size] [size]; // qartezi vra naveri texakayuman zangvachy
	// for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         arr_vessel[i][j] = 0;
    //     }
    // }
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