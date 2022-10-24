#include <iostream>
#include <cmath>


using namespace std;

void map_screen(int arr_vessel[][10],const int size) {
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

// patahakan mek hatanoc navery texadrox funkcia 
void ship_random_1(int arr_vessel[][10],const int size){ 
    cout << 1 << endl;
    int x = rand()%10;
    int y = rand()%10; 
    if(arr_vessel[x][y] == 0){
        arr_vessel[x][y] = 1;
        circle_close(arr_vessel,x,y);
        
    }else{
        ship_random_1(arr_vessel,size);
    }

}

void chack_ship_random_2(int arr_vessel[][10],int x,int y){
    int chack_arr[4][2];
    cout << 2 << endl;

    if(arr_vessel[x][y-1] == 0 && y-1 > 0){
        chack_arr[0][0] = x;
        chack_arr[0][1] = y-1;
    }
    if(arr_vessel[x][y+1] == 0 && y+1 < 10){
        chack_arr[1][0] = x;
        chack_arr[1][1] = y+1;
    }
    if(arr_vessel[x-1][y] == 0 && x-1 > 0){
        chack_arr[2][0] = x-1;
        chack_arr[2][1] = y;
    }
    if(arr_vessel[x+1][y] == 0 && x+1 < 10){
        chack_arr[3][0] = x+1;
        chack_arr[3][1] = y;
    }
    int k = rand() % 4;
    if(chack_arr[k][0] < 10 && chack_arr[k][0] > -1 && chack_arr[k][1] < 10 && chack_arr[k][1] > -1){
        arr_vessel[chack_arr[k][0]][chack_arr[k][1]] = 2;
        circle_close(arr_vessel,chack_arr[k][0],chack_arr[k][1]);
        circle_close(arr_vessel,x,y);
    }else{
        chack_ship_random_2(arr_vessel,x,y);
    }
}
// erkuhatanoc navery texadrox funkcia 
void ship_random_2(int arr_vessel[][10],const int size){ 
    int x = rand()%10;
    int y = rand()%10; 
    if(arr_vessel[x][y] == 0){
        
        arr_vessel[x][y] = 2;
        chack_ship_random_2(arr_vessel,x,y);
    }else{
        ship_random_2(arr_vessel,size);
    }

}
int chack_ship_random_4(int arr_vessel[][10],int x,int y){
    cout <<  4 << endl;
    int random_parties = rand()%4;
    switch (random_parties)
    {
        case (0):
            if(arr_vessel[x][y-3] == 0 && y-3 > -1){
                arr_vessel[x][y-3] = 4;
                arr_vessel[x][y-2] = 4;
                arr_vessel[x][y-1] = 4;
                arr_vessel[x][y] = 4;
                circle_close(arr_vessel,x,y-3);
                circle_close(arr_vessel,x,y-1);
                circle_close(arr_vessel,x,y-2);
                circle_close(arr_vessel,x,y);
                return 0;
            }else{
                chack_ship_random_4(arr_vessel,x,y);
            }
            break;
    
        
        
        case (1):
            if(arr_vessel[x][y+3] == 0 && y+3 < 10){
                arr_vessel[x][y+3] = 4;
                arr_vessel[x][y+2] = 4;
                arr_vessel[x][y+1] = 4;
                arr_vessel[x][y] = 4;
                circle_close(arr_vessel,x,y+3);
                circle_close(arr_vessel,x,y+1);
                circle_close(arr_vessel,x,y+2);
                circle_close(arr_vessel,x,y);
                return 0;
            }else{
                chack_ship_random_4(arr_vessel,x,y);
            }
            break;
    
        case (2):
            if(arr_vessel[x-3][y] == 0 && x-3 > -1)
            {
                arr_vessel[x-3][y] = 4;
                arr_vessel[x-2][y] = 4;
                arr_vessel[x-1][y] = 4;
                arr_vessel[x][y] = 4;
                circle_close(arr_vessel,x-3,y);
                circle_close(arr_vessel,x-2,y);
                circle_close(arr_vessel,x-1,y);
                circle_close(arr_vessel,x,y);
                return 0;

            }else{
                chack_ship_random_4(arr_vessel,x,y);
            }
            break;
    
        case (3):
            if(arr_vessel[x+3][y] == 0 && x+3 < 10){
                arr_vessel[x+3][y] = 4;
                arr_vessel[x+2][y] = 4;
                arr_vessel[x+1][y] = 4;
                arr_vessel[x][y] = 4;
                circle_close(arr_vessel,x+3,y);
                circle_close(arr_vessel,x+2,y);
                circle_close(arr_vessel,x+1,y);
                circle_close(arr_vessel,x,y);
                return 0;

            }else{
                chack_ship_random_4(arr_vessel,x,y);
            }
            break;
        default:
            break;
    }
    
    
    
    
    return 0;
}

void ship_random_4(int arr_vessel[][10],const int size){ 
    int x = rand()%10;
    int y = rand()%10; 
    
    if(arr_vessel[x][y] == 0){
        
        chack_ship_random_4(arr_vessel,x,y);
    }else{
        ship_random_4(arr_vessel,size);
    }

}
int chack_ship_random_3(int arr_vessel[][10],int x,int y){
    cout << 3 << endl;
    int random_parties = rand()%4;
    switch (random_parties)
    {
        case (0):
            if(arr_vessel[x][y-2] == 0 && y-2 > -1){
                
                arr_vessel[x][y-2] = 3;
                arr_vessel[x][y-1] = 3;
                arr_vessel[x][y] = 3;
                circle_close(arr_vessel,x,y-1);
                circle_close(arr_vessel,x,y-2);
                circle_close(arr_vessel,x,y);
                return 0;
            }else{
                chack_ship_random_3(arr_vessel,x,y);
            }
            break;
    
        
        
        case (1):
            if(arr_vessel[x][y+2] == 0 && y+2 < 10){
                
                arr_vessel[x][y+2] = 3;
                arr_vessel[x][y+1] = 3;
                arr_vessel[x][y] = 3;
                circle_close(arr_vessel,x,y+1);
                circle_close(arr_vessel,x,y+2);
                circle_close(arr_vessel,x,y);
                return 0;
            }else{
                chack_ship_random_3(arr_vessel,x,y);
            }
            break;
    
        case (2):
            if(arr_vessel[x-2][y] == 0 && x-2 > -1)
            {
                
                arr_vessel[x-2][y] = 3;
                arr_vessel[x-1][y] = 3;
                arr_vessel[x][y] = 3;
                
                circle_close(arr_vessel,x-2,y);
                circle_close(arr_vessel,x-1,y);
                circle_close(arr_vessel,x,y);
                return 0;

            }else{
                chack_ship_random_3(arr_vessel,x,y);
            }
            break;
    
        case (3):
            if(arr_vessel[x+2][y] == 0 && x+2 < 10){
                
                arr_vessel[x+2][y] = 3;
                arr_vessel[x+1][y] = 3;
                arr_vessel[x][y] = 3;
                
                circle_close(arr_vessel,x+2,y);
                circle_close(arr_vessel,x+1,y);
                circle_close(arr_vessel,x,y);
                return 0;

            }else{
                chack_ship_random_4(arr_vessel,x,y);
            }
            break;
    
      
        
    
    default:
        break;
    }
    
    
    
    
    return 0;
}

void ship_random_3(int arr_vessel[][10],const int size){ 
    int x = rand()%10;
    int y = rand()%10; 
   
    if(arr_vessel[x][y] == 0){
        
        chack_ship_random_3(arr_vessel,x,y);
    }else{
        ship_random_3(arr_vessel,size);
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
    
   
    ship_random_4(arr_vessel,size);
    ship_random_3(arr_vessel,size);
    ship_random_3(arr_vessel,size);
    ship_random_2(arr_vessel,size);
    ship_random_2(arr_vessel,size);
    ship_random_2(arr_vessel,size);
    for (int i = 0; i < 4; i++)
    {
        ship_random_1(arr_vessel,size);
    }
    
    

	map_screen(arr_vessel,size);
	return 0;
}
