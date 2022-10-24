#include <iostream>
#include <cmath>
#include "abstract_player.h"

using namespace std;






class Player_me : public  abstract_player{
public:
    int counter = 0;
    
    void shooting_at_coordinates(){
        int x = rand()%10;
        int y = rand()%10;
        if(shot_places[x][y]){
            while(shot_places[x][y]){
                x=rand()%10;
                y=rand()%10;
            }
        }else{
            
            if(ships[x][y] > 0 && ships[x][y] < 5){
                ships[x][y]= -1;
                ++counter;
                shot_places[x][y] = true;
            }else{
                ships[x][y]= -2;
                shot_places[x][y] = true;
            }
            if(ships[x][y]== -1){
                map_screen_2();
                cout<< "computer"<<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
                shooting_at_coordinates();
            }else{
                map_screen_2();
                cout<<  "computer" <<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
            }
        }
       
    }

    void map_screen_2(){
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(shot_places[i][j]){
                    if(ships[i][j]==-1){
                        cout << "X  ";
                    }else{
                        cout << "*  ";
                    }
                }else{
                    cout << "-  ";
                   
                }
            }
            cout << endl;
        }
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
    }
};
class Player_computer : public  abstract_player{
public:
    int counter = 0;
    void shooting_at_coordinates(){
        int x;
        int y;
        cout << "greq dzer krakelu naxntrch tivy uxxahayac arancqun 0-ic minchev 9-y " << endl;
        cin >> x;
        cout << "greq dzer krakelu naxntrch tivy uxxahayac horizonakan 0-ic minchev 9-y " << endl;
        cin >> y;
        if(shot_places[x][y]){
            cout << "aydtex krakac e";
            shooting_at_coordinates();
        }else{
            if(ships[x][y] > 0 && ships[x][y] < 5){
                ships[x][y]= -1;
                ++counter;
                shot_places[x][y] = true;
            }else{
                ships[x][y]= -2;
                shot_places[x][y] = true;
            }
            if(ships[x][y]==-1){
                map_screen_2();
                cout<< "es" <<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
                shooting_at_coordinates();
            }else{
                
                map_screen_2();
                cout<< "es" <<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
            }
        }
       

    }

    void map_screen_2(){
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(shot_places[i][j]){
                    if(ships[i][j]==-1){
                        cout << "X  ";
                    }else if(ships[i][j]==-2){
                        cout << "*  ";
                    }
                }else{
                    cout << "-  ";
                   
                }
            }
            cout << endl;
        }
        
    }
};


int  main() {
    srand(time(NULL));
    Player_me x;
    cout<<"es"<< endl;
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
   
    cout<<"------------------------------------------------------------------------------------"<<endl;
    Player_computer y;
    y.generate_ship_coordinates(4);
    y.generate_ship_coordinates(3);
    y.generate_ship_coordinates(3);
    y.generate_ship_coordinates(2);
    y.generate_ship_coordinates(2);
    y.generate_ship_coordinates(2);
    y.generate_ship_coordinates(1);
    y.generate_ship_coordinates(1);
    y.generate_ship_coordinates(1);
    y.generate_ship_coordinates(1);
    y.map_screen();
    cout<<"hamakargichy"<< endl;
    int counter_cycle = 0;
    while((!(x.counter == 20))||(!(x.counter == 20))){
        if(counter_cycle == 0){
            y.shooting_at_coordinates();
            
        }

        x.shooting_at_coordinates();
        y.shooting_at_coordinates();
        x.shooting_at_coordinates();
       
        
        
        
        
    }
    return 0;
}