#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int dice();
int result1,result2;

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
       {500,100,0,0},  //player1  use play[0]
       {500,100,0,0},  //player2  use play[1]
       {500,100,0,0},  //player3  use play[2]
       {500,100,0,0},  //player4  use play[3]
     };
    for(int k=0;k<4;k++){
       for(int i=0;i<3;i++){
           for(int j=0;j<10;j++){
               play[k].position[i][j] = 0;
                                }
                           }
                        }    // set up to 0

     int DiceNumber;

     int n[3]={1,2,3};
      // -----------------------up it's basic set up -------------------------------------------------------------------

      cout<<"�п�J���N�Ӧ���Y�X��1����l"<<endl;
      cin>>DiceNumber;
      result1=dice();
      cout<<"�Ĥ@����l��"<<result1<<endl;

      cout<<"�ЦA��J���N�Ӧ���Y�X��2����l"<<endl;
      cin>>DiceNumber;
      result2=dice();
      cout<<"�ĤG����l��"<<result2<<endl;

     cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<result1<<result2<<endl;

}

int dice(){
    //  ��l�{��
    int result;
    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%3)+1};
    }
    result = random[rand()%10000];
   return result;
}
