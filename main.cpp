#include <iostream>
#include <cmath>


using namespace std; 

void vessel_1(bool arr_vessel[][], int  arr_random_x [] ,int arr_random_y []) { //random 1 hatikanoc navery dnelu funkcia
	int  point_ship = 1;
	for (int i = 0; i < 4; i++)
	{
		arr_vessel[arr_random_x[i]][arr_random_y[i]];
	}
	
}






void random_vessel (int arr_vessel , int size){ // random navery dasavorelu funkcia 
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
            cout<< newRandomValue << endl;
        }  
    }
	cout << "================================================================="<< endl;
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
            cout<< newRandomValue << endl;
        }  
    }
	vessel_1(arr_vessel,arr_random_x, arr_random_y);
	cout << arr_vessel[0]<< endl;

		
    // }
}





int  main() {
	srand(time(NULL));
	const  int size = 10; // dashti erkararutyuny ev laynutyunt ev naveri qanaky 
	int arr_vessel [size] [size]; // qartezi vra naveri texakayuman zangvachy 
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr_vessel[i][j] = 0;
        }
        
    }
    cout << arr_vessel[0]<< endl;
    
	random_vessel(&arr_vessel[0][0], size);

	

	return 0;
}

