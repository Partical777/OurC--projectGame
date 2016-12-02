#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

struct  Player{

        int energy;
        int body;
        int x;  //x<3  it is galaxy name
        int y;  //y<20 it's star
        int position[3][10]; // it's mean whose star

};
//---------------------------------------main----------------------------------------------------------------------------------
int main(){
     struct Player play[] = {
       {500,100,0,0,},  //player1  use play[0]
       {500,100,0,0,},  //player2  use play[1]
       {500,100,0,0,},  //player3  use play[2]
       {500,100,0,0,},  //player4  use play[3]
     };
    for(int k=0;k<4;k++){
       for(int i=0;i<3;i++){
           for(int j=0;j<10;j++){
               play[k].position[i][j] = 0;
                                }
                           }
                        }    // set up to 0

      // -----------------------up it's basic set up -------------------------------------------------------------------

     cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<endl;

}
