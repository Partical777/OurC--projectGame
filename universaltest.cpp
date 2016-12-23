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

int dice(),ChooseDice1(),ChooseDice2(),InBlack(),YesNo(),GameStart(),Rule(),TruePosition(int),TruePositionOnlyName(int),Attack(int),FirstBase(int,int),SecondBase(int,int),ThirdBase(int,int),Energy(int),Body(int),Map(),BaseColor(int,int),Stage(int,int);
int Bet(),ChooseGame(),GuessNumber(),BigSmall(),Wormhole(int),SuddenlyEvent(int),Alien(int),Store(int),HowManyTool(int),UcantSeeMe(int);
int result1,result2,sum,xxglobal;
int skill = 6;
string DiceNumber,name[4];
int position[3][20],Tool[4]; // it's mean whose star  &  道具數值
                             // 道具在main中設立初始值
                             // 如有購買該道具 則0會變為1

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



        /*position[]=800
          800是完全初始狀態
          8 無意義
          0 代表屬於誰的   1 2 3 4 分別屬於4個玩家
          0 代表幾階基地   0 1 2 分別代表階數
          810 811 812 屬於player1*/

        /*BlackHole
          0表示 false 沒有在黑洞
          1表示 true 有在黑洞*/


};

struct  Drama1{  //星系1劇情
        string galaxy1 = "太陽系";
        string a0 = "太空站";
        string a1 = "火星";
        string a2 = "金星";
        string a3 = "水星";
        string a4 = "太陽";
        string a5 = "蟲洞";
        string a6 = "木星";
        string a7 = "土星";
        string a8 = "天王星  ";
        string a9 = "海王星  ";
        string a10 = "冥王星  ";
        string a11 = "  鬩神星  ";
        string a12 = "  穀神星  ";
        string a13 = "智神星  ";
        string a14 = "灶神星";
        string a15 = "鳥神星";
        string a16 = "妊神星";
        string a17 = "創神星";
        string a18 = "月亮";
        string a19 = "地球";
};
struct  Drama2{  //星系2劇情
        string galaxy2 = "星雲 群集";
        string b0 = "蟹狀星雲";
        string b1 = "貓眼星雲";
        string b2 = "馬頭星雲";
        string b3 = "螞蟻星雲";
        string b4 = "巴納德環星雲";
        string b5 = "回力棒星雲";
        string b6 = "老鷹星雲";
        string b7 = "愛斯基摩星雲";
        string b8 = "船底座η星雲";
        string b9 = "螺旋星雲";
        string b10 = "沙漏星雲";
        string b11 = "蟲洞";
        string b12 = "獵戶座星雲";
        string b13 = "鵜鶘星雲";
        string b14 = "紅矩形星雲";
        string b15 = "星際賭場";
        string b16 = "環狀星雲";
        string b17 = "玫瑰星雲";
        string b18 = "蜘蛛星雲";
        string b19 = "海鷗星雲";
};
struct  Drama3{  //星系3劇情
        string galaxy3 = "彗星 群集";
        string c0 = "梅克賀茲一號彗星";
        string c1 = "克魯茲族彗星";
        string c2 = "海爾-波普彗星";
        string c3 = "班尼特彗星";
        string c4 = "海爾博普彗星";
        string c5 = "包瑞利彗星";
        string c6 = "威斯特彗星";
        string c7 = "池谷關彗星";
        string c8 = "麥克諾特彗星";
        string c9 = "商店";
        string c10 = "柯侯德彗星";
        string c11 = "百武彗星";
        string c12 = "比拉彗星";
        string c13 = "恩克彗星";
        string c14 = "沃夫彗星";
        string c15 = "霍姆斯彗星";
        string c16 = "泰勒彗星";
        string c17 = "  蟲洞  ";
        string c18 = "林尼爾彗星";
        string c19 = "哈雷彗星";
};
struct story{    //剛開始的劇情
    string story0 = "╔═════════════════════════════════════╗\n║";
	string story1 = "║由於地球即將毀滅，四位大富翁為了生存，於是他們決定在地球以外的星球，      ║\n║";
	string story2 = "║建立自己的殖民地。但是他們要出發去爭奪自己的殖民地時，他們產生了激烈衝突，║\n║";
    string story3 = "║誰也不讓誰，於是他們決定各憑自己的力量，去爭奪自己的領地，彼此不互相往來，║\n║";
    string story4 = "║就這樣開始了激烈的你爭我奪......                                          ║\n║";
    string story5 = "╚═════════════════════════════════════╝\n";
 };
struct Player play[] = {
       {2000,100,0,0,0,0},  //player1  use play[0]
       {2000,100,0,0,0,0},  //player2  use play[1]
       {2000,100,0,0,0,0},  //player3  use play[2]
       {2000,100,0,0,0,0},  //player4  use play[3]
     };
struct Drama1 drama1;
struct Drama2 drama2;
struct Drama3 drama3;
//---------------------------------------main----------------------------------------------------------------------------------
int main(){
    int color[4]={12,14,10,11};

    for(int k=0;k<4;k++){
       for(int i=0;i<3;i++){
           for(int j=0;j<20;j++){
               position[i][j] = 800;
                                }
                           }
               Tool[k]=8000000;  //這是道具初始值

               play[k].energy = 2000;
               play[k].body = 100 ;
               play[k].x = 0 ;
               play[k].y = 0 ;
               play[k].z = 0 ;
               play[k].BlackHole = 0 ;
                        }    // set up to 800
               system("cls");


      // -----------------------up it's basic set up -------------------------------------------------------------------
int gamestart = GameStart();   //取得開始數據

    if(gamestart==3){   //開始遊戲
      struct story pass ;

      system("cls");     //顯示劇情
      cout<<pass.story0<<"                                                                          ║"<<endl;
      cout<<pass.story1<<"                                                                          ║"<<endl;
      cout<<pass.story2<<"                                                                          ║"<<endl;
      cout<<pass.story3<<"                                                                          ║"<<endl;
      cout<<pass.story4<<"                                                                          ║"<<endl;
      cout<<pass.story5;
      system("pause");

      system("cls");
      cout<<endl<<"請設定玩家1名稱:";  //設定玩家名稱
      cin>>name[0]; cout<<endl;
      cout<<"請設定玩家2名稱:";
      cin>>name[1]; cout<<endl;
      cout<<"請設定玩家3名稱:";
      cin>>name[2]; cout<<endl;
      cout<<"請設定玩家4名稱:";
      cin>>name[3]; cout<<endl;

    do{

      for(int xx=0;xx<4;xx++){
        system("cls");
        SetColor(color[xx]);
        cout<<"現在輪到 "<<xx+1<<" 號玩家 : "<<name[xx]<<endl;
        SetColor();
        cout<<"Energy  ";    //show energy
        Energy(xx);
        cout<<play[xx].energy<<" Tons"<<endl;
        cout<<"Body    ";      // show body
        Body(xx);
        cout<<play[xx].body<<"%"<<endl;
        xxglobal = xx ;
        Map();
        if(play[xx].BlackHole){  //測試是否在黑洞
           cout<<"您仍在第"<<play[xx].x+1<<"星系"<<endl<<"*仍被黑洞吸引中,請擲出相同的骰子點數以逃脫"<<endl<<endl;
        }else{
            cout<<endl<<"第"<<play[xx].z+1<<"圈"<<"   ";
            cout<<"您現在的位置是"<<endl;
            TruePositionOnlyName(xx);  //確定位置
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
                int AshortName = 0;
                switch(play[xx].x){  //隨機傳送至另兩星系
                   case 0:
                       do{
                        AshortName = dice();
                        play[xx].x = AshortName-1;
                       }while(play[xx].x == 0);
                    break;
                   case 1:
                       do{
                        AshortName = dice();
                        play[xx].x = AshortName-1;
                       }while(play[xx].x == 1);
                    break;
                   case 2:
                       do{
                        AshortName = dice();
                        play[xx].x = AshortName-1;
                       }while(play[xx].x == 2);
                    break;
                }

            }
            //--------------------------------------------------
        }else{  //如未在黑洞裡,繼續執行程序
            sum = result1 + result2 ;
            play[xx].y = play[xx].y + sum;  //加上骰子行走步數
            play[xx].energy = play[xx].energy - sum*2 ;
            if(play[xx].y>19){   //超過一圈時歸零且加上一圈統計
              play[xx].y = play[xx].y - 20;
              play[xx].z = play[xx].z+1;
              if(play[xx].x==0){   //如果在第一星系經過太空站會回復100TONS能源
              play[xx].energy = play[xx].energy + 100;
               }
            }
            if(play[xx].z>1){    //走超過兩圈者 進入黑洞
              play[xx].BlackHole = 1;
              play[xx].y = 0;
              play[xx].z = 0;
              cout<<endl<<"您不幸待在此星系過久,被星系中強大的黑洞束縛住,將暫停移動能力"<<endl;
            }else{  //------------------沒在黑洞且沒因超過兩圈進入黑洞
             //switch
               cout<<endl<<"您的位置移動至";
               int temporary = play[xx].x ;
               TruePosition(xx);  //確定位置
               cout<<endl;


               SuddenlyEvent(xx);   //突發事件
              // Alien(xx);   //外星人事件  合併於突發事件中

         if(temporary-play[xx].x==0){  //如果經過蟲洞後就不在執行
               if(play[xx].x==0){
                  if(play[xx].y==0){            //如果不是1-1
                  }else if(play[xx].y==5){      //        1-5
                  }else{
                      skill = 6;
                      Attack(xx);
                  }
               }else if(play[xx].x==1){
                  if(play[xx].y==11){            //        2-11
                  }else if(play[xx].y==15){      //        2-15
                  }else{
                      skill = 6;
                      Attack(xx);
                  }
               }else{
                   if(play[xx].y==9){            //        3-9
                   }else if(play[xx].y==17){     //        3-17
                   }else{
                      skill = 6;
                      Attack(xx);
                   }
               }
              }

               cout<<endl;
            }  //----------------------------------------------
        }

        if(play[xx].energy>2000){       //如果能源超過2000則只能2000
            play[xx].energy = 2000;
        }
        if(play[xx].body>100){         //如果機體超過100則只能100
            play[xx].body = 100;
        }


        cout<<endl<<"即將換下個玩家"<<endl;
        system("pause");
      }


    }while((play[0].energy>0&&play[0].body>0)&&(play[1].energy>0&&play[1].body>0)&&(play[2].energy>0&&play[2].body>0)&&(play[3].energy>0&&play[3].body>0));
    //遊戲結束
     string loser;
      if(play[0].energy>0&&play[0].body>0){
        loser = name[0];
      }else if(play[1].energy>0&&play[1].body>0){
        loser = name[1];
      }else if(play[2].energy>0&&play[2].body>0){
        loser = name[2];
      }else if(play[3].energy>0&&play[3].body>0){
        loser = name[3];
      }
      system("cls");
      cout<<endl<<"   ____                       ___                 "<<endl;
            cout<<"  / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ "<<endl;
            cout<<" | |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__|"<<endl;
            cout<<" | |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ |   "<<endl;
            cout<<"  \\____|\\__,_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|   "<<endl;

      cout<<endl<<"loser is "<<loser<<endl; //winner
      cout<<endl<<"請輸入任意按鍵回主選單"<<endl;
      system("pause");
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

int Energy(int xx){  //  energy~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     if(play[xx].energy>=2000){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉╣  ";}
else if(play[xx].energy>=1950){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋╣  ";}
else if(play[xx].energy>=1900){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉  ╣  ";}
else if(play[xx].energy>=1850){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋  ╣  ";}
else if(play[xx].energy>=1800){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉    ╣  ";}
else if(play[xx].energy>=1750){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋    ╣  ";}
else if(play[xx].energy>=1700){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉      ╣  ";}
else if(play[xx].energy>=1650){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋      ╣  ";}
else if(play[xx].energy>=1600){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉        ╣  ";}
else if(play[xx].energy>=1550){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋        ╣  ";}
else if(play[xx].energy>=1500){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉          ╣  ";}
else if(play[xx].energy>=1450){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▋          ╣  ";}
else if(play[xx].energy>=1400){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉            ╣  ";}
else if(play[xx].energy>=1350){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▋            ╣  ";}
else if(play[xx].energy>=1300){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉              ╣  ";}
else if(play[xx].energy>=1250){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▋              ╣  ";}
else if(play[xx].energy>=1200){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉                ╣  ";}
else if(play[xx].energy>=1150){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▋                ╣  ";}
else if(play[xx].energy>=1100){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉                  ╣  ";}
else if(play[xx].energy>=1050){cout<<"╠▉▉▉▉▉▉▉▉▉▉▋                  ╣  ";}
else if(play[xx].energy>=1000){cout<<"╠▉▉▉▉▉▉▉▉▉▉                    ╣  ";}
else if(play[xx].energy>=950 ){cout<<"╠▉▉▉▉▉▉▉▉▉▋                    ╣  ";}
else if(play[xx].energy>=900 ){cout<<"╠▉▉▉▉▉▉▉▉▉                      ╣  ";}
else if(play[xx].energy>=850 ){cout<<"╠▉▉▉▉▉▉▉▉▋                      ╣  ";}
else if(play[xx].energy>=800 ){cout<<"╠▉▉▉▉▉▉▉▉                        ╣  ";}
else if(play[xx].energy>=750 ){cout<<"╠▉▉▉▉▉▉▉▋                        ╣  ";}
else if(play[xx].energy>=700 ){cout<<"╠▉▉▉▉▉▉▉                          ╣  ";}
else if(play[xx].energy>=650 ){cout<<"╠▉▉▉▉▉▉▋                          ╣  ";}
else if(play[xx].energy>=600 ){cout<<"╠▉▉▉▉▉▉                            ╣  ";}
else if(play[xx].energy>=550 ){cout<<"╠▉▉▉▉▉▋                            ╣  ";}
else if(play[xx].energy>=500 ){cout<<"╠▉▉▉▉▉                              ╣  ";}
else if(play[xx].energy>=450 ){cout<<"╠▉▉▉▉▋                              ╣  ";}
else if(play[xx].energy>=400 ){cout<<"╠▉▉▉▉                                ╣  ";}
else if(play[xx].energy>=350 ){cout<<"╠▉▉▉▋                                ╣  ";}
else if(play[xx].energy>=300 ){SetColor(12);
                               cout<<"╠▉▉▉                                  ╣  ";SetColor();}
else if(play[xx].energy>=250 ){SetColor(12);
                               cout<<"╠▉▉▋                                  ╣  ";SetColor();}
else if(play[xx].energy>=200 ){SetColor(12);
                               cout<<"╠▉▉                                    ╣  ";SetColor();}
else if(play[xx].energy>=150 ){SetColor(12);
                               cout<<"╠▉▋                                    ╣  ";SetColor();}
else if(play[xx].energy>=100 ){SetColor(12);
                               cout<<"╠▉                                      ╣  ";SetColor();}
else if(play[xx].energy>=50 ){SetColor(12);
                               cout<<"╠▋                                      ╣  ";SetColor();}
else if(play[xx].energy>0 ){SetColor(0);
                               cout<<"╠▎                                      ╣  ";SetColor();}

}

int Body(int xx){   //body~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(play[xx].body>=100){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉╣  ";}
else if(play[xx].body>=95){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉  ╣  ";}
else if(play[xx].body>=90){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉    ╣  ";}
else if(play[xx].body>=85){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉      ╣  ";}
else if(play[xx].body>=80){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉        ╣  ";}
else if(play[xx].body>=75){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉          ╣  ";}
else if(play[xx].body>=70){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉▉            ╣  ";}
else if(play[xx].body>=65){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉▉              ╣  ";}
else if(play[xx].body>=60){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉▉                ╣  ";}
else if(play[xx].body>=55){cout<<"╠▉▉▉▉▉▉▉▉▉▉▉                  ╣  ";}
else if(play[xx].body>=50){cout<<"╠▉▉▉▉▉▉▉▉▉▉                    ╣  ";}
else if(play[xx].body>=45){cout<<"╠▉▉▉▉▉▉▉▉▉                      ╣  ";}
else if(play[xx].body>=40){cout<<"╠▉▉▉▉▉▉▉▉                        ╣  ";}
else if(play[xx].body>=35){cout<<"╠▉▉▉▉▉▉▉                          ╣  ";}
else if(play[xx].body>=30){cout<<"╠▉▉▉▉▉▉                            ╣  ";}
else if(play[xx].body>=25){cout<<"╠▉▉▉▉▉                              ╣  ";}
else if(play[xx].body>=20){cout<<"╠▉▉▉▉                                ╣  ";}
else if(play[xx].body>=15){SetColor(13);
                           cout<<"╠▉▉▉                                  ╣  ";SetColor();}
else if(play[xx].body>=10){SetColor(13);
                           cout<<"╠▉▉                                    ╣  ";SetColor();}
else if(play[xx].body>=5 ){SetColor(13);
                           cout<<"╠▉                                      ╣  ";SetColor();}
else if(play[xx].body>0 ){SetColor(13);
                           cout<<"╠▎                                      ╣  ";SetColor();}

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
    int lastch;
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
    lastch = 75;
    break;

    case 77 :
    SetColor();
    cout<< "\r YES " ;
    SetColor(240);
    cout<< " NO  " << flush ;
    SetColor();
    lastch = 77;
    break;

      }
          } // if(13)的

    }while(ch!=13);
       return lastch;
    /*   switch(lastch){
      case 75 :
       return 2;
       break;  //yes
      case 77 :
       return 1;
       break;  //no

    }*/


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

cout<<"一開始各方玩家有2000噸能源及一架完整的火箭船(100%)"<<endl;
cout<<"玩家4人，骰2顆3點的骰子"<<endl;
cout<<"有設定3個星系，星系中有多個恆星，行星，星雲或是彗星"<<endl;
cout<<"1. 每個星系都有一個蟲洞、停在此格即可藉由它自由選擇另外兩個星系其中之一"<<endl;
cout<<"2. 注意!!有隨機事件發生"<<endl;
cout<<"3. 每格皆有機會碰到外星人（突發事件maybe 1% or 2%）可能有好事或壞事發生"<<endl;
cout<<"4. 有  商店  賭場  太空站  各星系皆有一個"<<endl;
cout<<"5. 在同個星系超過兩圈者進入黑洞，直到再次擲出相同點數骰子，隨機傳入另外兩個星系"<<endl;
cout<<"6. 在黑洞1回合扣10 Tons能源"<<endl;
cout<<"7. 有3階段基地，"<<endl;
cout<<"建設基地消耗"<<endl;
cout<<"1階 消耗50 Tons，2階 消耗80 Tons，3階 消耗150 Tons"<<endl;
cout<<"其他人通過"<<endl;
cout<<"基地：1階扣10 Tons  機體扣2%，2階扣20 Tons  機體扣4%，3階扣50 Tons  機體扣8%"<<endl;
cout<<"每走1格扣5 Tons能源"<<endl;
cout<<"通過蟲洞扣較多，扣15 Tons"<<endl;
cout<<"一位玩家一種道具只能擁有一種"<<endl;

cout<<endl<<endl;
    return 0;
}

int TruePosition(int xx){

    switch(play[xx].x){  //先辨識在哪個星系
            case 0:
                switch(play[xx].y){  //在辨識在哪個位置
                  case 0: cout<<drama1.a0 ;break;
                  case 1: cout<<drama1.a1 ;break;
                  case 2: cout<<drama1.a2 ;break;
                  case 3: cout<<drama1.a3 ;break;
                  case 4: cout<<drama1.a4 ;break;
                  case 5: cout<<drama1.a5 ;
                          Wormhole(xx);
                          break;
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
                  case 11: cout<<drama2.b11 ;
                          Wormhole(xx);
                          break;
                  case 12: cout<<drama2.b12 ;break;
                  case 13: cout<<drama2.b13 ;break;
                  case 14: cout<<drama2.b14 ;break;
                  case 15: cout<<drama2.b15 ;//賭場
                          Bet();
                          break;
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
                  case 9: cout<<drama3.c9 ;
                          Store(xx);
                          break;
                  case 10: cout<<drama3.c10 ;break;
                  case 11: cout<<drama3.c11 ;break;
                  case 12: cout<<drama3.c12 ;break;
                  case 13: cout<<drama3.c13 ;break;
                  case 14: cout<<drama3.c14 ;break;
                  case 15: cout<<drama3.c15 ;break;
                  case 16: cout<<drama3.c16 ;break;
                  case 17: cout<<drama3.c17 ;
                          Wormhole(xx);
                          break;
                  case 18: cout<<drama3.c18 ;break;
                  case 19: cout<<drama3.c19 ;break;

                }
                break;


            }


}

int TruePositionOnlyName(int xx){

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


int Attack(int xx){
    int xA , yA , zA;
      xA = play[xx].x ;
      yA = play[xx].y ;
    if(position[xA][yA]==800){
        cout<<endl<<"您到了一個無人星球"<<endl;
        cout<<"是否要消耗50Tons在此建立基地"<<endl<<endl;
        zA = YesNo();
        if(zA==77){ //no
              cout<<endl<<"您未在此建立基地"<<endl;
        }else {//yes
              position[xA][yA] = position[xA][yA] + (xx+1)*10 ;
              play[xx].energy = play[xx].energy - 50 ;
              cout<<endl<<"Successful Building 一階段基地"<<endl;
              cout<<"Energy 減少了 50 Tons " <<endl;
        }
    }else if(position[xA][yA]==810||position[xA][yA]==811||position[xA][yA]==812){   //如果走到玩家1一階段基地

        if(xx==0){   //如果玩家1到了玩家1的領地
            switch(position[xA][yA]){
            case 810:
                FirstBase(xA,yA);
                break;
            case 811:
                SecondBase(xA,yA);
                break;
            case 812:
                ThirdBase(xA,yA);
                break;
            }
        }else{  //其他玩家走到玩家1的基地

         switch(position[xA][yA]){
            case 810:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[0]<<" 的一階段基地"<<endl<<"遭受內部防禦設施攻擊!"<<endl<<"Energy減少10 Tons  ,  Body受損2%"<<endl<<name[0]<<" 的Energy 增加10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[0].energy = play[0].energy + 10;
                }
                HowManyTool(xx);  //是否搶下對方的基地

                switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 2:
                       position[xA][yA] = 820;
                       break;
                       case 3:
                       position[xA][yA] = 830;
                       break;
                       case 4:
                       position[xA][yA] = 840;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 811:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[0]<<" 的二階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少20 Tons  ,  Body受損4%"<<endl<<name[0]<<" 的Energy 增加20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[0].energy = play[0].energy + 20;
                }
                HowManyTool(xx);  //是否搶下對方的基地

                switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 2:
                       position[xA][yA] = 821;
                       break;
                       case 3:
                       position[xA][yA] = 831;
                       break;
                       case 4:
                       position[xA][yA] = 841;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 810;

                break;
                }

                break;
            case 812:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[0]<<" 的三階段基地"<<endl<<"遭受內部防禦設施攻擊!!!"<<endl<<"Energy減少50 Tons  ,  Body受損8%"<<endl<<name[0]<<" 的Energy 增加50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[0].energy = play[0].energy + 50;
                }
                HowManyTool(xx);  //是否搶下對方的基地

                switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 2:
                       position[xA][yA] = 822;
                       break;
                       case 3:
                       position[xA][yA] = 832;
                       break;
                       case 4:
                       position[xA][yA] = 842;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 810;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 811;

                break;
                }

                break;
         }    //switch
        }

    }else if(position[xA][yA]==820||position[xA][yA]==821||position[xA][yA]==822){   //如果走到玩家2一階段基地

        if(xx==1){   //如果玩家2到了玩家2的領地
            switch(position[xA][yA]){
            case 820:
                FirstBase(xA,yA);
                break;
            case 821:
                SecondBase(xA,yA);
                break;
            case 822:
                ThirdBase(xA,yA);
                break;
            }
        }else{  //其他玩家走到玩家2的基地

          switch(position[xA][yA]){
            case 820:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[1]<<" 的一階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少10 Tons  ,  Body受損2%"<<endl<<name[1]<<" 的Energy 增加10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[1].energy = play[1].energy + 10;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 810;
                       break;
                       case 3:
                       position[xA][yA] = 830;
                       break;
                       case 4:
                       position[xA][yA] = 840;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 821:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[1]<<" 的二階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少20 Tons  ,  Body受損4%"<<endl<<name[1]<<" 的Energy 增加20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[1].energy = play[1].energy + 20;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 811;
                       break;
                       case 3:
                       position[xA][yA] = 831;
                       break;
                       case 4:
                       position[xA][yA] = 841;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 820;

                break;
                }

                break;
            case 822:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[1]<<" 的三階段基地"<<endl<<"遭受內部防禦設施攻擊!!!"<<endl<<"Energy減少50 Tons  ,  Body受損8%"<<endl<<name[1]<<" 的Energy 增加50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[1].energy = play[1].energy + 50;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 812;
                       break;
                       case 3:
                       position[xA][yA] = 832;
                       break;
                       case 4:
                       position[xA][yA] = 842;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 820;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 821;

                break;
                }

                break;
         }    //switch

        }

    }else if(position[xA][yA]==830||position[xA][yA]==831||position[xA][yA]==832){   //如果走到玩家3一階段基地

        if(xx==2){   //如果玩家3到了玩家3的領地
                switch(position[xA][yA]){
            case 830:
                FirstBase(xA,yA);
                break;
            case 831:
                SecondBase(xA,yA);
                break;
            case 832:
                ThirdBase(xA,yA);
                break;
            }
        }else{  //其他玩家走到玩家3的基地

          switch(position[xA][yA]){
            case 830:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[2]<<" 的一階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少10 Tons  ,  Body受損2%"<<endl<<name[2]<<" 的Energy 增加10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[2].energy = play[2].energy + 10;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 810;
                       break;
                       case 2:
                       position[xA][yA] = 820;
                       break;
                       case 4:
                       position[xA][yA] = 840;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 831:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[2]<<" 的二階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少20 Tons  ,  Body受損4%"<<endl<<name[2]<<" 的Energy 增加20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[2].energy = play[2].energy + 20;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 811;
                       break;
                       case 2:
                       position[xA][yA] = 821;
                       break;
                       case 4:
                       position[xA][yA] = 841;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 830;

                break;
                }

                break;
            case 832:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[2]<<" 的三階段基地"<<endl<<"遭受內部防禦設施攻擊!!!"<<endl<<"Energy減少50 Tons  ,  Body受損8%"<<endl<<name[2]<<" 的Energy 增加50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[2].energy = play[2].energy + 50;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 812;
                       break;
                       case 2:
                       position[xA][yA] = 822;
                       break;
                       case 4:
                       position[xA][yA] = 842;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 830;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 831;

                break;
                }

                break;
         }    //switch

        }

    }else if(position[xA][yA]==840||position[xA][yA]==841||position[xA][yA]==842){   //如果走到玩家4一階段基地

        if(xx==4){   //如果玩家4到了玩家4的領地
                switch(position[xA][yA]){
            case 840:
                FirstBase(xA,yA);
                break;
            case 841:
                SecondBase(xA,yA);
                break;
            case 842:
                ThirdBase(xA,yA);
                break;
            }
        }else{  //其他玩家走到玩家4的基地

          switch(position[xA][yA]){
            case 840:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[3]<<" 的一階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少10 Tons  ,  Body受損2%"<<endl<<name[3]<<" 的Energy 增加10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[3].energy = play[3].energy + 10;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 810;
                       break;
                       case 2:
                       position[xA][yA] = 820;
                       break;
                       case 3:
                       position[xA][yA] = 830;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 841:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[3]<<" 的二階段基地"<<endl<<"遭受內部防禦設施攻擊!!"<<endl<<"Energy減少20 Tons  ,  Body受損4%"<<endl<<name[3]<<" 的Energy 增加20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[3].energy = play[3].energy + 20;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 811;
                       break;
                       case 2:
                       position[xA][yA] = 821;
                       break;
                       case 3:
                       position[xA][yA] = 831;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 800;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 840;

                break;
                }

                break;
            case 842:
                UcantSeeMe(xx);
                if(skill!=1){  //免受攻擊
                cout<<"您現在走到 "<<name[3]<<" 的三階段基地"<<endl<<"遭受內部防禦設施攻擊!!!"<<endl<<"Energy減少50 Tons  ,  Body受損8%"<<endl<<name[3]<<" 的Energy 增加50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[3].energy = play[3].energy + 50;
                     }
                     HowManyTool(xx);  //是否搶下對方的基地

                     switch(skill){  //選擇道具
                case 2 :
                    switch(xx){   //攻佔對方地
                       case 1:
                       position[xA][yA] = 812;
                       break;
                       case 2:
                       position[xA][yA] = 822;
                       break;
                       case 3:
                       position[xA][yA] = 832;
                       break;
                    }
                break;
                case 3 :     //毀滅基地
                    position[xA][yA] = 800;

                break;
                case 4 :     //降低2階
                    position[xA][yA] = 840;

                break;
                case 5 :     //降低1階
                    position[xA][yA] = 841;

                break;
                }

                break;
         }    //switch

        }

    }
}

int FirstBase(int xA,int yA){
    int zA;
    int xx = xxglobal;
                cout<<"是否消耗80Tons來升級基地為二階段基地"<<endl;
                zA = YesNo();
                 if(zA==77){ //no
                    cout<<endl<<"您未升級基地"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    play[xx].energy = play[xx].energy - 80 ;
                    cout<<endl<<"成功升級為第二階段基地"<<endl;
                    cout<<"Energy 減少了 80 Tons " <<endl;
                }

}

int SecondBase(int xA,int yA){
    int zA;
    int xx = xxglobal;
                cout<<"是否消耗150Tons升級基地為三階段基地"<<endl;
                zA = YesNo();
                 if(zA==75){ //no
                    cout<<endl<<"您未升級基地"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    play[xx].energy = play[xx].energy - 150 ;
                    cout<<endl<<"成功升級為第三階段基地"<<endl;
                    cout<<"Energy 減少了 150 Tons " <<endl;
                }

}

int ThirdBase(int xA,int yA){
                cout<<"您的基地已升級至最高級,在此可修復機甲"<<endl;  //回復少許機甲讀數


}

int Map(){
    int yy = play[xxglobal].x ;
    string StarNameInMap[20];
    string GalaxyName;
    switch(yy){   // 顯示地圖區
  case 0:
      GalaxyName=drama1.galaxy1;
      StarNameInMap[0] = drama1.a0;
      StarNameInMap[1] = drama1.a1;
      StarNameInMap[2] = drama1.a2;
      StarNameInMap[3] = drama1.a3;
      StarNameInMap[4] = drama1.a4;
      StarNameInMap[5] = drama1.a5;
      StarNameInMap[6] = drama1.a6;
      StarNameInMap[7] = drama1.a7;
      StarNameInMap[8] = drama1.a8;
      StarNameInMap[9] = drama1.a9;
      StarNameInMap[10] = drama1.a10;
      StarNameInMap[11] = drama1.a11;
      StarNameInMap[12] = drama1.a12;
      StarNameInMap[13] = drama1.a13;
      StarNameInMap[14] = drama1.a14;
      StarNameInMap[15] = drama1.a15;
      StarNameInMap[16] = drama1.a16;
      StarNameInMap[17] = drama1.a17;
      StarNameInMap[18] = drama1.a18;
      StarNameInMap[19] = drama1.a19;
      break;
  case 1:
      GalaxyName=drama2.galaxy2;
      StarNameInMap[0] = drama2.b0;
      StarNameInMap[1] = drama2.b1;
      StarNameInMap[2] = drama2.b2;
      StarNameInMap[3] = drama2.b3;
      StarNameInMap[4] = drama2.b4;
      StarNameInMap[5] = drama2.b5;
      StarNameInMap[6] = drama2.b6;
      StarNameInMap[7] = drama2.b7;
      StarNameInMap[8] = drama2.b8;
      StarNameInMap[9] = drama2.b9;
      StarNameInMap[10] = drama2.b10;
      StarNameInMap[11] = drama2.b11;
      StarNameInMap[12] = drama2.b12;
      StarNameInMap[13] = drama2.b13;
      StarNameInMap[14] = drama2.b14;
      StarNameInMap[15] = drama2.b15;
      StarNameInMap[16] = drama2.b16;
      StarNameInMap[17] = drama2.b17;
      StarNameInMap[18] = drama2.b18;
      StarNameInMap[19] = drama2.b19;
      break;
  case 2:
      GalaxyName=drama3.galaxy3;
      StarNameInMap[0] = drama3.c0;
      StarNameInMap[1] = drama3.c1;
      StarNameInMap[2] = drama3.c2;
      StarNameInMap[3] = drama3.c3;
      StarNameInMap[4] = drama3.c4;
      StarNameInMap[5] = drama3.c5;
      StarNameInMap[6] = drama3.c6;
      StarNameInMap[7] = drama3.c7;
      StarNameInMap[8] = drama3.c8;
      StarNameInMap[9] = drama3.c9;
      StarNameInMap[10] = drama3.c10;
      StarNameInMap[11] = drama3.c11;
      StarNameInMap[12] = drama3.c12;
      StarNameInMap[13] = drama3.c13;
      StarNameInMap[14] = drama3.c14;
      StarNameInMap[15] = drama3.c15;
      StarNameInMap[16] = drama3.c16;
      StarNameInMap[17] = drama3.c17;
      StarNameInMap[18] = drama3.c18;
      StarNameInMap[19] = drama3.c19;
      break;
    }


    BaseColor(yy,0);
    cout<<"                                     ";
    Stage(yy,0);
    cout<<endl;
    cout<<"                                      "<<"★"<<endl;  //1
    cout<<"                                    "<<StarNameInMap[0]<<endl<<endl;  //1
    SetColor();

    BaseColor(yy,19);
    cout<<"                               ";
    Stage(yy,19);  SetColor();                                 //20
    BaseColor(yy,1);
    cout<<"            ";
    Stage(yy,1);
    cout<<endl;   SetColor();                                 //2

    BaseColor(yy,19);
    cout<<"                               "<<"★"<<"      ";  SetColor();   //20
    BaseColor(yy,1);
    cout<<"      "<<"★"<<"              "<<endl;             SetColor();    //2`
    BaseColor(yy,19);
    cout<<"                               "<<StarNameInMap[19]<<"     ";SetColor();  //20
    BaseColor(yy,1);
    cout<<"      "<<StarNameInMap[1]<<"              "<<endl<<endl;    SetColor();//2

    BaseColor(yy,18);
    cout<<"                          ";
    Stage(yy,18);  SetColor();                                 //19
    BaseColor(yy,2);
    cout<<"                      ";
    Stage(yy,2);
    cout<<endl;   SetColor();                                 //3

    BaseColor(yy,18);
    cout<<"                          "<<"★"<<"          ";    SetColor();//19
    BaseColor(yy,2);
    cout<<"            "<<"★"<<"              "<<endl;        SetColor();//3
    BaseColor(yy,18);
    cout<<"                          "<<StarNameInMap[18]<<"         ";  SetColor();  //19
    BaseColor(yy,2);
    cout<<"            "<<StarNameInMap[2]<<"              "<<endl<<endl;SetColor();    //3

    BaseColor(yy,17);
    cout<<"                    ";
    Stage(yy,17);  SetColor();                                 //18
    BaseColor(yy,3);
    cout<<"                                  ";
    Stage(yy,3);
    cout<<endl;   SetColor();                                 //4

    BaseColor(yy,17);
    cout<<"                    "<<"★"<<"            ";          SetColor(); //18
    BaseColor(yy,3);
    cout<<"                      "<<"★"<<"     "<<endl;         SetColor(); //4
    BaseColor(yy,17);
    cout<<"                    "<<StarNameInMap[17]<<"            ";        SetColor();   //18
    BaseColor(yy,3);
    cout<<"                   "<<StarNameInMap[3]<<"     "<<endl<<endl; SetColor(); //4

    BaseColor(yy,16);
    cout<<"               ";
    Stage(yy,16);  SetColor();                                 //17
    BaseColor(yy,4);
    cout<<"                                             ";
    Stage(yy,4);
    cout<<endl;   SetColor();                                 //5

    BaseColor(yy,16);
    cout<<"               "<<"★"<<"                    ";           SetColor(); //17
    BaseColor(yy,4);
    cout<<GalaxyName<<"                   "<<"★"<<"     "<<endl;        SetColor();//5
    BaseColor(yy,16);
    cout<<"               "<<StarNameInMap[16]<<"                   ";         SetColor();//17
    BaseColor(yy,4);
    cout<<"                       "<<StarNameInMap[4]<<"     "<<endl<<endl;SetColor();  //5

    BaseColor(yy,15);
    cout<<"          ";
    Stage(yy,15);  SetColor();                                 //16
    BaseColor(yy,5);
    cout<<"                                                       ";
    Stage(yy,5);
    cout<<endl;   SetColor();                                 //6

    BaseColor(yy,15);
    cout<<"          "<<"★"<<"                        ";                 SetColor(); //16
    BaseColor(yy,5);
    cout<<"                               "<<"★"<<"     "<<endl;         SetColor();  //6
    BaseColor(yy,15);
    cout<<"          "<<StarNameInMap[15]<<"                        ";               SetColor();//16
    BaseColor(yy,5);
    cout<<"                            "<<StarNameInMap[5]<<"     "<<endl<<endl; SetColor(); //6

    BaseColor(yy,14);
    cout<<"      ";
    Stage(yy,14);  SetColor();                                 //15
    BaseColor(yy,6);
    cout<<"                                                                ";
    Stage(yy,6);
    cout<<endl;   SetColor();                                 //7

    BaseColor(yy,14);
    cout<<"      "<<"★"<<"                             ";                    SetColor();//15
    BaseColor(yy,6);
    cout<<"                                   "<<"★"<<"     "<<endl;         SetColor();//7
    BaseColor(yy,14);
    cout<<"      "<<StarNameInMap[14]<<"                             ";                  SetColor();//15
    BaseColor(yy,6);
    cout<<"                                "<<StarNameInMap[6]<<"     "<<endl<<endl; SetColor(); //7

    BaseColor(yy,13);
    cout<<" ";
    Stage(yy,13);  SetColor();                                 //14
    BaseColor(yy,12);
    cout<<"          ";
    Stage(yy,12);  SetColor();                                 //13
    BaseColor(yy,11);
    cout<<"           ";
    Stage(yy,11);  SetColor();                                 //12
    BaseColor(yy,10);
    cout<<"           ";
    Stage(yy,10);  SetColor();                                 //11
    BaseColor(yy,9);
    cout<<"           ";
    Stage(yy,9);  SetColor();                                 //10
    BaseColor(yy,8);
    cout<<"          ";
    Stage(yy,8);  SetColor();                                 //9
    BaseColor(yy,7);
    cout<<"           ";
    Stage(yy,7);
    cout<<endl;   SetColor();                                 //8

    BaseColor(yy,13);
    cout<<" "<<"★"<<"          ";  SetColor(); //14
    BaseColor(yy,12);
    cout<<"★"<<"           ";  SetColor(); //13
    BaseColor(yy,11);
    cout<<"★"<<"           ";  SetColor(); //12
    BaseColor(yy,10);
    cout<<"★"<<"           ";  SetColor(); //11
    BaseColor(yy,9);
    cout<<"★"<<"           ";  SetColor(); //10
    BaseColor(yy,8);
    cout<<"★"<<"          ";  SetColor(); //9
    BaseColor(yy,7);
    cout<<"★"<<"           "<<endl; SetColor();  //8
    BaseColor(yy,13);
    cout<<" "<<StarNameInMap[13]<<"   ";  SetColor(); //14
    BaseColor(yy,12);
    cout<<StarNameInMap[12]<<"   ";  SetColor(); //13
    BaseColor(yy,11);
    cout<<StarNameInMap[11]<<"    ";  SetColor(); //12
    BaseColor(yy,10);
    cout<<StarNameInMap[10]<<"    ";  SetColor(); //11
    BaseColor(yy,9);
    cout<<StarNameInMap[9]<<"     ";  SetColor(); //10
    BaseColor(yy,8);
    cout<<StarNameInMap[8]<<"     ";  SetColor(); //9
    BaseColor(yy,7);
    cout<<StarNameInMap[7]<<"       "<<endl<<endl;  SetColor(); //8

}

int BaseColor(int a,int b){    //設置佔領區顏色

    switch(position[a][b]){
        case 800:
            SetColor();
        break;
        case 810:
            SetColor(12);
        break;
        case 811:
            SetColor(12);
        break;
        case 812:
            SetColor(12);
        break;
        case 820:
            SetColor(14);
        break;
        case 821:
            SetColor(14);
        break;
        case 822:
            SetColor(14);
        break;
        case 830:
            SetColor(10);
        break;
        case 831:
            SetColor(10);
        break;
        case 832:
            SetColor(10);
        break;
        case 840:
            SetColor(11);
        break;
        case 841:
            SetColor(11);
        break;
        case 842:
            SetColor(11);
        break;
    }
}

int Stage(int a,int b){    //設置階段基地
          if(position[a][b]==810||position[a][b]==820||position[a][b]==830||position[a][b]==840){
        cout<<" * ";
    }else if(position[a][b]==811||position[a][b]==821||position[a][b]==831||position[a][b]==841){
        cout<<" **";
    }else if(position[a][b]==812||position[a][b]==822||position[a][b]==832||position[a][b]==842){
        cout<<"***";
    }else{
        cout<<"   ";
    }

}

int Bet(){     //  賭場大函數
    cout<<"您來到了星際賭場，將可以使用能源作為籌碼，以換取更多能源"<<endl<<endl;
    int latech = 0;
    cout<<"請選擇遊戲"<<endl;
    cout<<"猜數字可獲得三倍能源，比大小可獲得兩倍能源"<<endl;
    latech = ChooseGame();
    if(latech==77){   //right's
        BigSmall();
    }else{
        GuessNumber();
    }

}

int ChooseGame(){//選擇遊戲種類　和YesNo()一樣
    int ch;
    int lastch;
    SetColor(240);

    cout<< "\r 猜數字 " ;
    SetColor();
    cout<< " 比大小 "  << flush;

    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){
    case 75 :
    SetColor(240);
    cout<< "\r 猜數字 " ;
    SetColor();
    cout<< " 比大小 " << flush ;
    lastch = 75;
    break;

    case 77 :
    SetColor();
    cout<< "\r 猜數字 " ;
    SetColor(240);
    cout<< " 比大小 " << flush ;
    SetColor();
    lastch = 77;
    break;

      }
          } // if(13)的

    }while(ch!=13);
       return lastch;

}

int GuessNumber(){     //猜數字
    int betmoney = 0;
    int result123456789 = 0;
    int betnumber = 0;
    do{
    cout<<endl<<"請輸入欲賭博能源數量 : ";
    cin>>betmoney;
    }while(betmoney>play[xxglobal].energy);


    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%5)+1};
    }
    result123456789 = random[rand()%10000];

    cout<<endl<<"請輸入任一數字1~5，如猜中即可獲得能源三倍的獎勵"<<endl;
    do{
    cin>>betnumber;
    }while(betnumber>5||betnumber<1);

    if(betnumber==result123456789){
        play[xxglobal].energy = play[xxglobal].energy + betmoney*2 ;

        //------------------如獲勝可繼續賭博
        cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
        cout<<"恭喜獲勝！！"<<endl;

          cout<<"是否繼續 猜數字換能源"<<endl;     //是否繼續賭博
          result123456789 = YesNo();       //result123456789 重複使用
          if(result123456789==77){ //no
              cout<<endl<<"將離開星際賭場"<<endl;
             }else {//yes
              GuessNumber();
             }
         //----------------------------------------

    }else{
        play[xxglobal].energy = play[xxglobal].energy - betmoney ;
        cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
        cout<<"您的運氣不好，猜錯了，請再接再厲"<<endl;

    }
/*
    cout<<"是否繼續 猜數字換能源"<<endl;     //是否繼續賭博
    result123456789 = YesNo();       //result123456789 重複使用
    if(result123456789==77){ //no
              cout<<endl<<"將離開星際賭場"<<endl;
        }else {//yes
              GuessNumber();
        }
*/
}

int BigSmall(){   //比大小
    int betmoney = 0;
    int result123456789 = 0;
    int betnumber = 0;
    do{
    cout<<endl<<"請輸入欲賭博能源數量 : ";
    cin>>betmoney;
    }while(betmoney>play[xxglobal].energy);


    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%20)+1};
    }
    result123456789 = random[rand()%10000];


    int ch;
    int lastch;
    SetColor(240);

    cout<< "\r 比大 " ;
    SetColor();
    cout<< " 比小 "  << flush;

    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){
    case 75 :
    SetColor(240);
    cout<< "\r 比大 " ;
    SetColor();
    cout<< " 比小 " << flush ;
    lastch = 75;
    break;

    case 77 :
    SetColor();
    cout<< "\r 比大 " ;
    SetColor(240);
    cout<< " 比小 " << flush ;
    SetColor();
    lastch = 77;
    break;

      }
          } // if(13)的

    }while(ch!=13);

    string nonumber ;
    cout<<endl<<"請輸入任意字以隨機抽牌，如比較勝利可獲得二倍的獎勵"<<endl;
    cin>>nonumber ;
    do{

            for(int i=0;i<10000;i++)
           {
             random[i]={(rand()%20)+1};
           }
             betnumber = random[rand()%10000];

    }while(betnumber>20||betnumber<1);


    if(lastch==77){   //比小

         if(betnumber<result123456789){
         play[xxglobal].energy = play[xxglobal].energy + betmoney ;
         cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
         cout<<"恭喜獲勝！！"<<endl;

         //----------------如獲勝可繼續賭博
          cout<<"是否繼續 比大小換能源"<<endl;     //是否繼續賭博
          result123456789 = YesNo();       //result123456789 重複使用
          if(result123456789==77){ //no
              cout<<endl<<"將離開星際賭場"<<endl;
          }else {//yes
              GuessNumber();
          }
        //--------------------------------

         }else{
         play[xxglobal].energy = play[xxglobal].energy - betmoney ;
         cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
         cout<<"您的運氣不好，猜錯了，請再接再厲"<<endl;
    }

    }else{           //比大

        if(betnumber>result123456789){
        play[xxglobal].energy = play[xxglobal].energy + betmoney ;
        cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
        cout<<"恭喜獲勝！！"<<endl;
        //----------------如獲勝可繼續賭博
          cout<<"是否繼續 比大小換能源"<<endl;     //是否繼續賭博
          result123456789 = YesNo();       //result123456789 重複使用
          if(result123456789==77){ //no
              cout<<endl<<"將離開星際賭場"<<endl;
          }else {//yes
              GuessNumber();
          }
        //--------------------------------
        }else{
        play[xxglobal].energy = play[xxglobal].energy - betmoney ;
        cout<<"莊家的數字為"<<result123456789<<","<<"您的數字為"<<betnumber<<endl;
        cout<<"您的運氣不好，猜錯了，請再接再厲"<<endl;
    }

    }



}

int Wormhole(int xx){         //蟲洞函式
    int AshortSystem = 0;
                switch(play[xx].x){  //選擇傳送至另兩星系
                   case 0:
                       do{
                        cout<<endl<<"請輸入欲前往星系，除了第一星系外"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x <= 0||play[xx].x>2);
                       play[xx].y = 0 ;

                    break;
                   case 1:
                       do{
                        cout<<endl<<"請輸入欲前往星系，除了第二星系外"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x == 1||play[xx].x<0||play[xx].x>2);
                       play[xx].y = 0 ;

                    break;
                   case 2:
                       do{
                        cout<<endl<<"請輸入欲前往星系，除了第三星系外"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x >=2||play[xx].x<0);
                       play[xx].y = 0 ;

                    break;
                }
                play[xx].energy = play[xx].energy - 15 ;
                cout<<"Success moving !"<<endl;
}


int SuddenlyEvent(int xx){    // 突發事件程序
    //  隨機程序
    int result;
    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%20)+1};
    }
    result = random[rand()%10000];

    if(result==7){   //由此5%的機率觸發事件

            for(int i=0;i<10000;i++)
           {
             random[i]={(rand()%10)+1};
           }
             result = random[rand()%10000];

        switch(result){
            case 1:
                cout<<endl<<"突發事件:"<<endl<<"外星人突然在大富翁面前出現，以友善的方式接待他們，並提供他們100Tons能源"<<endl<<endl;
                play[xx].energy = play[xx].energy + 100;
                break;
            case 2:
                cout<<endl<<"突發事件:"<<endl<<"大富翁抵達下一個目的地時，外星人突然出現在面前，搶走大富翁150Tons能源"<<endl<<endl;
                play[xx].energy = play[xx].energy - 150;
                break;
            case 3:
                cout<<endl<<"突發事件:"<<endl<<"在飛行途中，突然遭受外星人攻擊，機體受損10%"<<endl<<endl;
                play[xx].body = play[xx].body - 10;
                break;
            case 4:
                cout<<endl<<"突發事件:"<<endl<<"大富翁正前往目的地，突然遇到外星人，外星人看他太弱，扔個武器就走了"<<endl<<endl;
                cout<<"獲得電磁脈衝*1"<<endl<<endl;
                Tool[xx] = 8100000;
                break;
            case 5:
                cout<<endl<<"突發事件:"<<endl<<"遭受小行星群撞擊，機體嚴重受損20%，在閃避的過程中，能源也造成了額外消耗50Tons"<<endl<<endl;
                play[xx].body = play[xx].body - 25;
                play[xx].energy = play[xx].energy - 50;
                break;
            case 6:
                cout<<endl<<"突發事件:"<<endl<<"行駛途中遇超新星爆炸，造成機體15%損壞"<<endl<<endl;
                play[xx].body = play[xx].body- 15;
                break;
            case 7:
                cout<<endl<<"突發事件:"<<endl<<"星體活動異常，突然噴發大量電子和中子，造成儀器損壞，機體減少5%"<<endl<<endl;
                play[xx].body = play[xx].body - 5;
                break;
            case 8:
                cout<<endl<<"突發事件:"<<endl<<"重力異常，引起導航方向錯誤，額外消耗了45Tons能源"<<endl<<endl;
                play[xx].energy = play[xx].energy - 45;
                break;
            case 9:
                cout<<endl<<"突發事件:"<<endl<<"飛行途中，發現了一顆滿是能源的星體，獲得大量的能源+150Tons"<<endl<<endl;
                play[xx].energy = play[xx].energy + 150;
                break;
            case 10:
                cout<<endl<<"突發事件:"<<endl<<"突然天神降臨，教導這些愚昧的富翁技術，能源+100機體+10%"<<endl<<endl;
                play[xx].energy = play[xx].energy + 100;
                play[xx].body = play[xx].body + 10;
                break;

        }



    }
}

/*int Alien(int xx){       //突發遇到外星人
    //  隨機程序
    int result;
    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%40)+1};
    }
    result = random[rand()%10000];

    if(result==35){   //由此2.5%的機率觸發事件
         for(int i=0;i<10000;i++)
        {
           random[i]={(rand()%2)+1};
        }
        result = random[rand()%10000];    //在隨機取出1/2的機率碰到好的或壞的外星人

        if(result==1){   //如果碰到好的
        //外星人事件
        }else{           //如果碰到壞的
        //外星人事件
        }
    }

}*/

int Store(int xx){  //確定6種
       int s = Tool[xx];
       int num[6];
       int toolchoose = 0;

       cout<<"歡迎來到宇宙便利站"<<endl<<"這裡有很多道具任你選擇"<<endl;

       for(int z = 0; z<6 ;z++){   //辨識已有何種道具 取出每一位數
         num[z] = s%10;
         s = s/10 ;
       }

       //   80 0 0 0 0 0    從後面開始數
       //    5 4 3 2 1 0 位

       if(s!=8000000){    //如果有道具

       cout<<"您目前持有";
       // 如果有下列道具
       if(num[0]==1){cout<<"回復機體 ";}
       if(num[1]==1){cout<<"光學隱形 ";}
       if(num[2]==1){cout<<"駭入星體 ";}
       if(num[3]==1){cout<<"死星 Death Star ";}
       if(num[4]==1){cout<<"核彈 ";}
       if(num[5]==1){cout<<"電磁脈衝 ";}
       }



       cout<<endl<<"可購買道具項目,如已購買之項目將不再增加"<<endl;
       cout<<"1.回復機體((用能源換防禦機體   2.光學隱形((免受攻擊"<<endl<<"3.駭入星體((攻佔對方基地   4.死星 Death Star((毀滅對方基地"<<endl<<"5.核彈((降低二階基地   6.電磁脈衝((降低一階基地   7. Cancel"<<endl;
       cout<<"請選擇您想購買道具之編號，一回合只能購買一種"<<endl;
       do{
            cin>>toolchoose;
       }while(toolchoose>7||toolchoose<1);

       toolchoose = toolchoose - 1 ;

       switch(toolchoose){
       case 0 : play[xx].energy = play[xx].energy - 100;
                play[xx].body = play[xx].body + 10;
                cout<<endl<<"success buying 回復機體10%"<<endl;
                break;                                                 //回復機體
       case 1 : if (num[1]==1){Tool[xx] = Tool[xx]+10;play[xx].energy = play[xx].energy - 40 ;cout<<endl<<"success buying 光學隱形"<<endl;}; break;        //光學隱形
       case 2 : if (num[2]==1){Tool[xx] = Tool[xx]+100;play[xx].energy = play[xx].energy - 100 ;cout<<endl<<"success buying 駭入星體"<<endl;}; break;       //駭入星體
       case 3 : if (num[3]==1){Tool[xx] = Tool[xx]+1000;play[xx].energy = play[xx].energy - 75 ;cout<<endl<<"success buying 死星 Death Star"<<endl;}; break;      //死星 Death Star
       case 4 : if (num[4]==1){Tool[xx] = Tool[xx]+10000;play[xx].energy = play[xx].energy - 50 ;cout<<endl<<"success buying 核彈"<<endl;}; break;     //核彈
       case 5 : if (num[5]==1){Tool[xx] = Tool[xx]+100000;play[xx].energy = play[xx].energy - 25 ;cout<<endl<<"success buying 電磁脈衝"<<endl;}; break;    //電磁脈衝

       }
}

int UcantSeeMe(int xx){
       int s = Tool[xx];
       int num[6];

       for(int z = 0; z<6 ;z++){   //辨識已有何種道具 取出每一位數
         num[z] = s%10;
         s = s/10 ;
       }
       //   80 0 0 0 0 0    從後面開始數
       //    5 4 3 2 1 0 位

       if(num[1]==1){    //如果有道具

       cout<<endl<<endl<<"您目前持有:";
       // 如果有下列道具
       //if(num[0]==1){cout<<"1.回復機體 ";}
       cout<<"1.光學隱形";
/*     if(num[2]==1){cout<<"2.駭入星體 ";}
       if(num[3]==1){cout<<"3.死星 Death Star ";}
       if(num[4]==1){cout<<"4.核彈 ";}
       if(num[5]==1){cout<<"5.電磁脈衝 ";}
  */
       cout<<endl<<"是否使用光學隱形,如要使用請按1,如不使用請按 6 "<<endl;
       do{
       cin>>skill;
       }while(skill!=1||skill!=6);
       if(skill==1){
        Tool[xx] = Tool[xx] - 10;
        cout<<"成功躲過對方的偵測器"<<endl;
       }

       }


}


int HowManyTool(int xx){
       int s = Tool[xx];
       int num[6];

       for(int z = 0; z<6 ;z++){   //辨識已有何種道具 取出每一位數
         num[z] = s%10;
         s = s/10 ;
       }

       //   80 0 0 0 0 0    從後面開始數
       //    5 4 3 2 1 0 位

       if(Tool[xx]!=8000000&&Tool[xx]!=8000010){    //如果有道具

       cout<<"您目前持有:";
       // 如果有下列道具
       //if(num[0]==1){cout<<"1.回復機體 ";}
       //if(num[1]==1){cout<<"1.光學隱形 ";}
       if(num[2]==1){
            cout<<"2.駭入星體 ";
       }
       if(num[3]==1){
            cout<<"3.死星 Death Star ";
            }
       if(num[4]==1){
            cout<<"4.核彈 ";
       }
       if(num[5]==1){
            cout<<"5.電磁脈衝 ";
       }

       cout<<endl<<"請選擇使用道具，如不使用請按 6 "<<endl;
       do{
       cin>>skill;
       }while(skill>6||skill<2);

         switch(skill){
        case 2:
            if(num[2]==1){
        cout<<endl<<"已使用 駭入星體 , 佔據了對方基地,變為我方陣地"<<endl;
        Tool[xx] = Tool[xx]-100;
            }else{
              cout<<"你並無此項道具,直接取消使用"<<endl;
            }
        break;
        case 3:
            if(num[3]==1){
        cout<<endl<<"死星 Death Star , 已將敵方奢師破壞殆盡,回歸無人星球"<<endl;
        Tool[xx] = Tool[xx]-1000;
            }else{
              cout<<"你並無此項道具,直接取消使用"<<endl;
            }
        break;
        case 4:
            if(num[4]==1){
        cout<<endl<<"核彈 , 已讓敵方損失慘重,降低二階基地"<<endl;
        Tool[xx] = Tool[xx]-10000;
            }else{
              cout<<"你並無此項道具,直接取消使用"<<endl;
            }
        break;
        case 5:
            if(num[5]==1){
        cout<<endl<<"電磁脈衝 , 已讓敵方遭受些許毀損,降低一階基地"<<endl;
        Tool[xx] = Tool[xx]-100000;
            }else{
              cout<<"你並無此項道具,直接取消使用"<<endl;
            }
        break;


         }

    }


}
