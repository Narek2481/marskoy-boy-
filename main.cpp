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


// patahakan mek hatanoc navery texadrox funkcia 
void ship_random_1(int arr_vessel[][10],const int size){ 
    
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
    
    if(arr_vessel[x][y-1] == 0 && y-1 > 0){
        chack_arr[0][0] = x;
        chack_arr[0][1] = y-1;
    }
    
    
    if(arr_vessel[x][y+1] == 0 && y+1 < 10){
        chack_arr[0][0] = x;
        chack_arr[0][1] = y+1;
    }
    
    
    if(arr_vessel[x-1][y] == 0 && x-1 > 0){
        chack_arr[0][0] = x-1;
        chack_arr[0][1] = y;
    }
    
    
   
    if(arr_vessel[x+1][y] == 0 && x+1 < 10){
        chack_arr[0][0] = x+1;
        chack_arr[0][1] = y;
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
    int ship_lenght = 2;
    int x = rand()%10;
    int y = rand()%10; 
    
    
    if(arr_vessel[x][y] == 0){
        
        arr_vessel[x][y] = 2;
        chack_ship_random_2(arr_vessel,x,y);
    }else{
        ship_random_2(arr_vessel,size);
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
    for (int i = 0; i < 4; i++)
    {
        ship_random_1(arr_vessel,size);
    }
    
    ship_random_2(arr_vessel,size);
    ship_random_2(arr_vessel,size);
    ship_random_2(arr_vessel,size);
    
    

	map_screen(arr_vessel,size);

	

	return 0;
}
