#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int dice(),ChooseDice1(),ChooseDice2();
int result1,result2,DiceNumber;

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



     int n[3]={1,2,3};
      // -----------------------up it's basic set up -------------------------------------------------------------------

    do{
      for(int xx=0;xx<4;xx++){

        ChooseDice1();
        ChooseDice2();


     cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<result1<<result2<<endl;


      }
    }while((play[0].energy!=0&&play[0].body!=0)&&(play[1].energy!=0&&play[1].body!=0)&&(play[2].energy!=0&&play[2].body!=0)&&(play[3].energy!=0&&play[3].body!=0));

}

int ChooseDice1(){

    cout<<"請輸入任意個位數擲出第1顆骰子"<<endl;
      cin>>DiceNumber;
      result1=dice();
      cout<<"第一顆骰子為"<<result1<<endl;

}

int ChooseDice2(){

    cout<<"請再輸入任意個位數擲出第2顆骰子"<<endl;
      cin>>DiceNumber;
      result2=dice();
      cout<<"第二顆骰子為"<<result2<<endl;

}

int dice(){
    //  骰子程序
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
