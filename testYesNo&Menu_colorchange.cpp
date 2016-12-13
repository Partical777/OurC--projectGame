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

int YesNo(),GameStart();



void SetColor(int color = 7)  //更改顏色函式
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}
//-------------------------------------------------------------------------------------------------
int main(){
   GameStart();
   YesNo();
}
//-------------------------------------------------------------------------------------------------

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
    cout<<"╔═╗┌┬┐┌─┐┬─┐  ╔╦╗┬─┐┌─┐┬┌─"<<endl;
cout<<"╚═╗  │  ├─┤├┬┘    ║  ├┬┘├┤  ├┴┐"<<endl;
cout<<"╚═╝  ┴  ┴  ┴┴└─    ╩  ┴└─└─┘┴  ┴"<<endl<<endl;


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
            cout<<"╔═╗┌┬┐┌─┐┬─┐  ╔╦╗┬─┐┌─┐┬┌─"<<endl;
cout<<"╚═╗  │  ├─┤├┬┘    ║  ├┬┘├┤  ├┴┐"<<endl;
cout<<"╚═╝  ┴  ┴  ┴┴└─    ╩  ┴└─└─┘┴  ┴"<<endl<<endl;
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
            cout<<"╔═╗┌┬┐┌─┐┬─┐  ╔╦╗┬─┐┌─┐┬┌─"<<endl;
cout<<"╚═╗  │  ├─┤├┬┘    ║  ├┬┘├┤  ├┴┐"<<endl;
cout<<"╚═╝  ┴  ┴  ┴┴└─    ╩  ┴└─└─┘┴  ┴"<<endl<<endl;
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
            cout<<"╔═╗┌┬┐┌─┐┬─┐  ╔╦╗┬─┐┌─┐┬┌─"<<endl;
cout<<"╚═╗  │  ├─┤├┬┘    ║  ├┬┘├┤  ├┴┐"<<endl;
cout<<"╚═╝  ┴  ┴  ┴┴└─    ╩  ┴└─└─┘┴  ┴"<<endl<<endl;
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
