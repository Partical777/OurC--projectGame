#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int dice(),ChooseDice1(),ChooseDice2(),InBlack();
int result1,result2;
string DiceNumber;

struct  Player{

        int energy;
        int body;
        int x;  //x<3  it is galaxy name
        int y;  //y<20 it's star
        int z;  //z loop number(圈數)
        bool BlackHole; //是否在黑洞
        int position[3][10]; // it's mean whose star


        /*position[]=800
          800是完全初始狀態
          8 無意義
          0 代表幾階基地   1 2 3 分別代表階數
          0 代表屬於誰的   1 2 3 4 分彆屬於4個玩家*/
        /*BlackHole
          0表示 false 沒有在黑洞
          1表示 true 有在黑洞*/

};
//---------------------------------------main----------------------------------------------------------------------------------
int main(){
     struct Player play[] = {
       {500,100,0,0,0,0},  //player1  use play[0]
       {500,100,0,0,0,0},  //player2  use play[1]
       {500,100,0,0,0,0},  //player3  use play[2]
       {500,100,0,0,0,0},  //player4  use play[3]
     };
    for(int k=0;k<4;k++){
       for(int i=0;i<3;i++){
           for(int j=0;j<10;j++){
               play[k].position[i][j] = 800;
                                }
                           }
                        }    // set up to 800


      // -----------------------up it's basic set up -------------------------------------------------------------------

    do{
      for(int xx=0;xx<4;xx++){
        system("cls");
        cout<<"現在輪到第"<<xx+1<<"位玩家"<<endl;
        if(play[xx].BlackHole){  //測試是否在黑洞
           cout<<endl<<"*您仍被黑洞吸引中,請擲出相同的骰子點數以逃脫"<<endl<<endl;
        }
        ChooseDice1(); //擲出第一顆骰子
        ChooseDice2(); //擲出第二顆骰子
            //--------------------------------------------------
         if(play[xx].BlackHole){  //測試是否在黑洞
           play[xx].BlackHole = InBlack()-1;
            if(play[xx].BlackHole){
                cout<<"您已成功逃脫黑洞的束縛,將被隨機傳送到另外兩個星系之一"<<endl<<endl;
            }else{
                cout<<"您未逃脫黑洞的束縛,將繼續被限制行動"<<endl<<endl;
            }
            //--------------------------------------------------
        }else{  //如未在黑洞裡,繼續執行程序


        }

        cout<<endl<<"即將換下個玩家"<<endl;
        system("pause");
      }

      cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<result1<<result2<<endl;

    }while((play[0].energy!=0&&play[0].body!=0)&&(play[1].energy!=0&&play[1].body!=0)&&(play[2].energy!=0&&play[2].body!=0)&&(play[3].energy!=0&&play[3].body!=0));

}
//------------------------------------main up----------------------------------------------------

int ChooseDice1(){

    cout<<endl<<"請輸入任意個位數擲出第1顆骰子"<<endl;
      cin>>DiceNumber;
      result1=dice();
      cout<<"第一顆骰子為"<<result1<<endl;

}

int ChooseDice2(){

    cout<<endl<<"請再輸入任意個位數擲出第2顆骰子"<<endl;
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

int InBlack(){
    //  黑洞程序
        if(result1==result2){ //測試兩個骰子是否一樣
           return 1 ;
        }else{
           return 2 ;
        }
}

