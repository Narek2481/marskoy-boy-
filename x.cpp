#include <iostream>
#include <cmath>


using namespace std;

void map_screen(int arr_vessel[][10],const int size){ 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(arr_vessel[i][j]==0){
                cout << "-  ";
            }else{
                cout << arr_vessel[i][j] << "  ";
            }
        }
        cout << endl;
    }
    
}
void circle_close(int arr_vessel[][10],int x,int y){
   
        if(y - 1 < 10 && y - 1 > -1){
            if(arr_vessel[x][y - 1] == 0){
                arr_vessel[x][y - 1] = 5;
            }
            
        }
        if(y + 1 < 10 && y + 1 > -1){
            if(arr_vessel[x][y + 1] == 0){
                arr_vessel[x][y + 1] = 5;
            }
            
        }
        if(x - 1 < 10 && x - 1 > -1){
            if(arr_vessel[x - 1][y] == 0){
                arr_vessel[x - 1][y] = 5;
            }
            
        }
        if(x + 1 < 10 && x + 1 > -1){
            if( arr_vessel[x + 1][y] == 0){
                arr_vessel[x + 1][y] = 5;
            }
            
        }
        if(y - 1 < 10 && y - 1 > -1 && x - 1 < 10 && x - 1 > -1){
            if( arr_vessel[x - 1][y - 1] == 0){
                arr_vessel[x - 1][y - 1] = 5;
            }
            
        }
        if(y + 1 < 10 && y + 1 > -1 && x + 1 < 10 && x + 1 > -1){
            if(arr_vessel[x + 1][y + 1] == 0){
                arr_vessel[x + 1][y + 1] = 5;
            }
            
        }
        if(y + 1 < 10 && y + 1 > -1 && x - 1 < 10 && x - 1 > -1){
            if(arr_vessel[x - 1][y + 1] == 0){
                arr_vessel[x - 1][y + 1] = 5;
            }
            

        }
        if(y - 1 < 10 && y - 1 > -1 && x + 1 < 10 && x + 1 > -1){
            if(arr_vessel[x + 1][y - 1] == 0){
                arr_vessel[x + 1][y - 1] = 5;
            }
            
        }
    
}

void paint_ship(int x,int y,int x_end,int y_end,bool is_x,int arr_vessel[][10],int ship_size){
    cout<< 3 << endl;
    if(is_x == true){
        for (int i = y; i <= y_end; i++)
        {
            arr_vessel[x][i] = ship_size;
            
        }
        for (int i = y; i <= y_end; i++)
        {
            circle_close(arr_vessel,i,y);
        }
        
    }else{
        for (int i = x; i <= x_end; i++)
        {
            arr_vessel[i][y] = ship_size;
        }
        for (int i = x; i <= x_end; i++)
        {
            circle_close(arr_vessel,i,y);
        }
    }
}

void chack_ship_way (int arr_vessel[][10],int enpty_fileds[][2],int x,int y,int ship_size){
    

    int enpty_fileds_rand = rand() % 4;
    bool is_x;
    if(enpty_fileds[enpty_fileds_rand][0] < 10 && enpty_fileds[enpty_fileds_rand][0] > -1){
        if(enpty_fileds[enpty_fileds_rand][0] == x){
            if(x < enpty_fileds[enpty_fileds_rand][0] ){
            for (int i = x; i <= enpty_fileds[enpty_fileds_rand][1]; i++)
            {
                if(!(arr_vessel[x][i] == 0)){
                    enpty_fileds[enpty_fileds_rand][0] == 10;
                    chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
                }
            }
            is_x = true;
            if(y > enpty_fileds[enpty_fileds_rand][1]){
                paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
                
            }else{
                paint_ship(x,enpty_fileds[enpty_fileds_rand][1],x,y,is_x,arr_vessel,ship_size);
            }
            }else{
                for (int i = enpty_fileds[enpty_fileds_rand][1]; i <= x; i++)
            {
                if(!(arr_vessel[x][i] == 0)){
                    enpty_fileds[enpty_fileds_rand][0] == 10;
                    chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
                }
            }
            is_x = true;
            if(y > enpty_fileds[enpty_fileds_rand][1]){
                paint_ship(x,enpty_fileds[enpty_fileds_rand][1],x,y,is_x,arr_vessel,ship_size);
                
            }else{
                
                paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
            }
            }
        }else if(enpty_fileds[enpty_fileds_rand][1] == y){
            if(y < enpty_fileds[enpty_fileds_rand][0]){
            for (int i = y; i <= enpty_fileds[enpty_fileds_rand][0]; i++)
            {
                if(!(arr_vessel[i][y] == 0)){
                    enpty_fileds[enpty_fileds_rand][1] == 10;
                    chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
                }
            }
            is_x = false;
            if(y > enpty_fileds[enpty_fileds_rand][1]){
                paint_ship(enpty_fileds[enpty_fileds_rand][0],y,x,y,is_x,arr_vessel,ship_size);
            }else{
                paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
            }
            }else{
                for (int i = enpty_fileds[enpty_fileds_rand][0]; i <= y; i++)
            {
                if(!(arr_vessel[i][y] == 0)){
                    enpty_fileds[enpty_fileds_rand][1] == 10;
                    chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
                }
            }
            is_x = false;
            if(y > enpty_fileds[enpty_fileds_rand][1]){
                paint_ship(enpty_fileds[enpty_fileds_rand][0],y,x,y,is_x,arr_vessel,ship_size);
            }else{
                paint_ship(x,y,x,enpty_fileds[enpty_fileds_rand][1],is_x,arr_vessel,ship_size);
            }
            }
        }else{
             chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
        }
    }else{
        chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
    }
}

void ship_random_all(int arr_vessel[][10],const int size,int ship_size){ 

    int x = rand()%10;
    int y = rand()%10; 
    if(arr_vessel[x][y] == 0){
        int enpty_fileds [4][2]{
            {10,10},
            {10,10},
            {10,10},
            {10,10}
        };
        if(x+ship_size-1 < 10 && x+ship_size-1 > -1 && arr_vessel[x+ship_size-1][y] == 0){
            enpty_fileds[0][0] = x+ship_size-1;
            enpty_fileds[0][1] = y;
            
        }
        if(y+ship_size-1 < 10 && y+ship_size-1 > -1 && arr_vessel[x][y+ship_size-1] == 0){
            enpty_fileds[1][1] = y+ship_size-1;
            enpty_fileds[1][0] = x;

        }
        if(x-(ship_size-1) < 10 && x-(ship_size-1) > -1 && arr_vessel[x-(ship_size-1)][y] == 0){
            enpty_fileds[2][0] = x-(ship_size-1);
            enpty_fileds[2][1] = y;
        }
        if(y-(ship_size-1) < 10 && y-(ship_size-1) > -1 && arr_vessel[x][y-(ship_size-1)] == 0){
            enpty_fileds[3][1] = y-(ship_size-1);
            enpty_fileds[3][0] = x;
        }
        chack_ship_way(arr_vessel,enpty_fileds,x,y,ship_size);
    }else{
        ship_random_all(arr_vessel,size,ship_size);
    }
}

int  main() {
    srand(time(NULL));
	const  int size = 10; // dashti erkararutyuny ev laynutyunt ev naveri qanaky 
	int arr_vessel[size] [size]; // qartezi vra naveri texakayuman zangvachy 
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr_vessel[i][j] = 0;
        }
    }
    ship_random_all(arr_vessel,size,4);
    ship_random_all(arr_vessel,size,3);
    // ship_random_all(arr_vessel,size,3);
    // ship_random_all(arr_vessel,size,2);
    // ship_random_all(arr_vessel,size,2);
    // ship_random_all(arr_vessel,size,2);
    // ship_random_all(arr_vessel,size,1);
    // ship_random_all(arr_vessel,size,1);
    // ship_random_all(arr_vessel,size,1);
    // ship_random_all(arr_vessel,size,1);
	map_screen(arr_vessel,size);

    return 0;
}