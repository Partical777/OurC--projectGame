#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int dice(),ChooseDice1(),ChooseDice2(),InBlack(),YesNo(),GameStart(),Rule(),TruePosition(int);
int result1,result2,sum;
string DiceNumber;


void SetColor(int color = 7)  //更改顏色函式
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}

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

struct  Drama1{  //星系1劇情
        string a0 = "星系1星球1";
        string a1 = "星系1星球2";
        string a2 = "星系1星球3";
        string a3 = "星系1星球4";
        string a4 = "星系1星球5";
        string a5 = "星系1星球6";
        string a6 = "星系1星球7";
        string a7 = "星系1星球8";
        string a8 = "星系1星球9";
        string a9 = "星系1星球10";
        string a10 = "星系1星球11";
        string a11 = "星系1星球12";
        string a12 = "星系1星球13";
        string a13 = "星系1星球14";
        string a14 = "星系1星球15";
        string a15 = "星系1星球16";
        string a16 = "星系1星球17";
        string a17 = "星系1星球18";
        string a18 = "星系1星球19";
        string a19 = "星系1星球20";
};
struct  Drama2{  //星系2劇情
        string b0 = "星系2星球1";
        string b1 = "星系2星球2";
        string b2 = "星系2星球3";
        string b3 = "星系2星球4";
        string b4 = "星系2星球5";
        string b5 = "星系2星球6";
        string b6 = "星系2星球7";
        string b7 = "星系2星球8";
        string b8 = "星系2星球9";
        string b9 = "星系2星球10";
        string b10 = "星系2星球11";
        string b11 = "星系2星球12";
        string b12 = "星系2星球13";
        string b13 = "星系2星球14";
        string b14 = "星系2星球15";
        string b15 = "星系2星球16";
        string b16 = "星系2星球17";
        string b17 = "星系2星球18";
        string b18 = "星系2星球19";
        string b19 = "星系2星球20";
};
struct  Drama3{  //星系3劇情
        string c0 = "星系3星球1";
        string c1 = "星系3星球2";
        string c2 = "星系3星球3";
        string c3 = "星系3星球4";
        string c4 = "星系3星球5";
        string c5 = "星系3星球6";
        string c6 = "星系3星球7";
        string c7 = "星系3星球8";
        string c8 = "星系3星球9";
        string c9 = "星系3星球10";
        string c10 = "星系3星球11";
        string c11 = "星系3星球12";
        string c12 = "星系3星球13";
        string c13 = "星系3星球14";
        string c14 = "星系3星球15";
        string c15 = "星系3星球16";
        string c16 = "星系3星球17";
        string c17 = "星系3星球18";
        string c18 = "星系3星球19";
        string c19 = "星系3星球20";
};
struct Player play[] = {
       {500,100,0,0,0,0},  //player1  use play[0]
       {500,100,0,0,0,0},  //player2  use play[1]
       {500,100,0,0,0,0},  //player3  use play[2]
       {500,100,0,0,0,0},  //player4  use play[3]
     };
//---------------------------------------main----------------------------------------------------------------------------------
int main(){


    for(int k=0;k<4;k++){
       for(int i=0;i<3;i++){
           for(int j=0;j<10;j++){
               play[k].position[i][j] = 800;
                                }
                           }
                        }    // set up to 800


      // -----------------------up it's basic set up -------------------------------------------------------------------
int gamestart = GameStart();   //取得開始數據

    if(gamestart==3){   //開始遊戲
    do{
      for(int xx=0;xx<4;xx++){
        system("cls");
        SetColor(14);
        cout<<"現在輪到第 "<<xx+1<<" 位玩家"<<endl;
        SetColor();

        if(play[xx].BlackHole){  //測試是否在黑洞
           cout<<endl<<"*您仍被黑洞吸引中,請擲出相同的骰子點數以逃脫"<<endl<<endl;
        }else{
            cout<<endl<<"您現在的位置是";
            TruePosition(xx);  //確定位置
            cout<<"第"<<play[xx].z+1<<"圈"<<endl;
        }
            //先顯示一次位置
        ChooseDice1(); //擲出第一顆骰子
        ChooseDice2(); //擲出第二顆骰子
            //--------------------------------------------------
         if(play[xx].BlackHole){  //測試是否在黑洞
           play[xx].BlackHole = InBlack()-1;
            if(play[xx].BlackHole){
                cout<<"您未逃脫黑洞的束縛,將繼續被限制行動"<<endl<<endl;
            }else{
                cout<<"您已成功逃脫黑洞的束縛,將被隨機傳送到另外兩個星系之一"<<endl<<endl;
            }
            //--------------------------------------------------
        }else{  //如未在黑洞裡,繼續執行程序
            sum = result1 + result2 ;
            play[xx].y = play[xx].y + sum;  //加上骰子行走步數
            if(play[xx].y>20){   //超過一圈時歸零且加上一圈統計
              play[xx].y = play[xx].y - 20;
              play[xx].z = play[xx].z+1;
            }
            if(play[xx].z>1){    //走超過兩圈者 進入黑洞
              play[xx].BlackHole = 1;
              play[xx].y = 0;
              play[xx].z = 0;
              cout<<endl<<"您不幸待在此星系過久,被星系中強大的黑洞束縛住,將暫停移動能力"<<endl;
            }else{
             //switch
               cout<<endl<<"您的位置移動至";
               TruePosition(xx);  //確定位置
               cout<<endl;
            }
        }




        cout<<endl<<"即將換下個玩家"<<endl;
        system("pause");
      }

      cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<result1<<result2<<endl;

    }while((play[0].energy!=0&&play[0].body!=0)&&(play[1].energy!=0&&play[1].body!=0)&&(play[2].energy!=0&&play[2].body!=0)&&(play[3].energy!=0&&play[3].body!=0));
    //遊戲結束
      cout<<"The Game Over,winner is "; //winner
      return main();
    //將設置跳回選單會離開~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  } else if (gamestart==2){   //規則說明
         Rule();
         system("PAUSE");
         system("cls");
         return main();
  } else {                    //離開遊戲
      cout<<endl<<endl<<endl<<endl<<"                 ";
      SetColor(207);
     cout<<"即將離開遊戲....."<<endl;
      SetColor();

  }

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

int YesNo(){  //選擇yes or no 的函式

    int ch;

    cout<< "choose yes or no" <<endl;
    SetColor(240);

    cout<< "\r YES " ;
    SetColor();
    cout<< " NO "  << flush;

    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){
    case 75 :
    SetColor(240);
    cout<< "\r YES " ;
    SetColor();
    cout<< " NO  " << flush ;
    break;

    case 77 :
    SetColor();
    cout<< "\r YES " ;
    SetColor(240);
    cout<< " NO  " << flush ;
    SetColor();
    break;

      }
          } // if(13)的

    }while(ch!=13);
       switch(ch){
      case 75 :
       return 2;
       break;  //yes
      case 77 :
       return 1;
       break;  //no

    }


}

int GameStart(){
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;



    int ch;

    cout<<"                    ";
    SetColor(240);
    cout<< " 遊戲開始 " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " 規則說明 "  <<endl<<endl<< flush;
    cout<<"                    ";
    cout<< " 離開遊戲 "  <<endl<< flush;
int updown = 0; //上下鍵位置變數
    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){     //上下鍵控制
    case 72 :
        if(updown>0){
            updown = updown-1;
        }
    break;
    case 80 :
        if(updown<2){
            updown = updown+1;
        }
    break;
      }

      switch(updown){
    case 0 :
        system("cls");
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
    cout<<"                    ";  //space*20
        SetColor(240);
    cout<< " 遊戲開始 " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " 規則說明 " <<endl<<endl<< flush;
    cout<<"                    ";
    cout<< " 離開遊戲 "  <<endl<< flush;
    break;

    case 1 :
        system("cls");
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
        SetColor();
        cout<<"                    ";
    cout<< " 遊戲開始 " <<endl<<endl<< flush;
    cout<<"                    ";
    SetColor(240);
    cout<< " 規則說明 " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " 離開遊戲 "  <<endl<< flush;
    break;

    case 2 :
        system("cls");
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
        SetColor();
        cout<<"                    ";
    cout<< " 遊戲開始 " <<endl<<endl<< flush;;
    SetColor();
    cout<<"                    ";
    cout<< " 規則說明 " <<endl<<endl<< flush;
    cout<<"                    ";
    SetColor(240);
    cout<< " 離開遊戲 "  <<endl<< flush;
    SetColor();
    break;

      }
          } // if(13)的

    }while(ch!=13);
       switch(updown){
      case 0 :
       return 3;
       break;  //start
      case 1 :
       return 2;
       break;  //rule
      case 2 :
        return 1;
        break; // leave

    }

}

int Rule(){   //在此輸入規則
    system("cls");

    cout<<"12345678945612348974"<<endl;
    cout<<"12345678945612348974"<<endl;
    cout<<"12345678945612348974"<<endl;
    cout<<"12345678945612348974"<<endl;
    cout<<"12345678945612348974"<<endl;
    return 0;
}

int TruePosition(int xx){
     struct Drama1 drama1;
     struct Drama2 drama2;
     struct Drama3 drama3;

    switch(play[xx].x){  //先辨識在哪個星系
            case 0:
                switch(play[xx].y){  //在辨識在哪個位置
                  case 0: cout<<drama1.a0 ;break;
                  case 1: cout<<drama1.a1 ;break;
                  case 2: cout<<drama1.a2 ;break;
                  case 3: cout<<drama1.a3 ;break;
                  case 4: cout<<drama1.a4 ;break;
                  case 5: cout<<drama1.a5 ;break;
                  case 6: cout<<drama1.a6 ;break;
                  case 7: cout<<drama1.a7 ;break;
                  case 8: cout<<drama1.a8 ;break;
                  case 9: cout<<drama1.a9 ;break;
                  case 10: cout<<drama1.a10 ;break;
                  case 11: cout<<drama1.a11 ;break;
                  case 12: cout<<drama1.a12 ;break;
                  case 13: cout<<drama1.a13 ;break;
                  case 14: cout<<drama1.a14 ;break;
                  case 15: cout<<drama1.a15 ;break;
                  case 16: cout<<drama1.a16 ;break;
                  case 17: cout<<drama1.a17 ;break;
                  case 18: cout<<drama1.a18 ;break;
                  case 19: cout<<drama1.a19 ;break;

                }
                break;

            case 1:
                switch(play[xx].y){
                  case 0: cout<<drama2.b0 ;break;
                  case 1: cout<<drama2.b1 ;break;
                  case 2: cout<<drama2.b2 ;break;
                  case 3: cout<<drama2.b3 ;break;
                  case 4: cout<<drama2.b4 ;break;
                  case 5: cout<<drama2.b5 ;break;
                  case 6: cout<<drama2.b6 ;break;
                  case 7: cout<<drama2.b7 ;break;
                  case 8: cout<<drama2.b8 ;break;
                  case 9: cout<<drama2.b9 ;break;
                  case 10: cout<<drama2.b10 ;break;
                  case 11: cout<<drama2.b11 ;break;
                  case 12: cout<<drama2.b12 ;break;
                  case 13: cout<<drama2.b13 ;break;
                  case 14: cout<<drama2.b14 ;break;
                  case 15: cout<<drama2.b15 ;break;
                  case 16: cout<<drama2.b16 ;break;
                  case 17: cout<<drama2.b17 ;break;
                  case 18: cout<<drama2.b18 ;break;
                  case 19: cout<<drama2.b19 ;break;

                }
                break;

            case 2:
                switch(play[xx].y){
                  case 0: cout<<drama3.c0 ;break;
                  case 1: cout<<drama3.c1 ;break;
                  case 2: cout<<drama3.c2 ;break;
                  case 3: cout<<drama3.c3 ;break;
                  case 4: cout<<drama3.c4 ;break;
                  case 5: cout<<drama3.c5 ;break;
                  case 6: cout<<drama3.c6 ;break;
                  case 7: cout<<drama3.c7 ;break;
                  case 8: cout<<drama3.c8 ;break;
                  case 9: cout<<drama3.c9 ;break;
                  case 10: cout<<drama3.c10 ;break;
                  case 11: cout<<drama3.c11 ;break;
                  case 12: cout<<drama3.c12 ;break;
                  case 13: cout<<drama3.c13 ;break;
                  case 14: cout<<drama3.c14 ;break;
                  case 15: cout<<drama3.c15 ;break;
                  case 16: cout<<drama3.c16 ;break;
                  case 17: cout<<drama3.c17 ;break;
                  case 18: cout<<drama3.c18 ;break;
                  case 19: cout<<drama3.c19 ;break;

                }
                break;

            }


}
