#include <iostream>
#include <cmath>


using namespace std; 
// dashty nkarelu funkcia 
void map_screen(bool arr_vessel[][10],const int size){ 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(arr_vessel[i][j]){
                cout << "+  ";
            }else{
                cout << "-  ";
            }
        }
        cout << endl;
    }
    
}
//random 1 hatikanoc navery dnelu funkcia
void vessel_1(bool arr_vessel[][10], int  arr_random_x [] ,int arr_random_y [],const int size) { 
    
	int  point_ship = 1;
	for (int i = 0; i < 4; i++)
	{
		arr_vessel[arr_random_x[i]][arr_random_y[i]]= true;
	}
	map_screen(arr_vessel,size);
}






void random_vessel (bool arr_vessel[][10], int size) { // random navery dasavorelu funkcia 
	int arr_random_x [size];
	int arr_random_y [size];

    bool alredyThere_x;
	bool alredyThere_y;
    for (int i = 0; i < size;)
    {
        alredyThere_x = true;
        int newRandomValue = rand() % 10;
        
        for (int j = 0; j < i ; j++)
        {
            if(arr_random_x[j] == newRandomValue){
                alredyThere_x = false;
            }
        }
        if(alredyThere_x){
            arr_random_x[i] = newRandomValue;
            i++;
            
        }  
    }
	
	for (int i = 0; i < size;)
    {
        alredyThere_y = true;
        int newRandomValue = rand() % 10;
        
        for (int j = 0; j < i ; j++)
        {
            if(arr_random_y[j] == newRandomValue){
                alredyThere_y = false;
            }
        }
        if(alredyThere_y){
            arr_random_y[i] = newRandomValue;
            i++;
           
        }  
    }
	vessel_1(arr_vessel,arr_random_x, arr_random_y,size);
	


    
}




int  main() {
	const  int size = 10; // dashti erkararutyuny ev laynutyunt ev naveri qanaky 
	bool arr_vessel[size] [size]; // qartezi vra naveri texakayuman zangvachy 
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr_vessel[i][j] = false;
        }
        
    }
    
    
	random_vessel(arr_vessel, size);

	

	return 0;
}
