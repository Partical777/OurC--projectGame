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



void SetColor(int color = 7)  //����C��禡
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

int YesNo(){  //���yes or no ���禡

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
          } // if(13)��

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
    cout<<"�����ߢz�s�{�z�w�{�s�w�{  �����ߢs�w�{�z�w�{�s�z�w"<<endl;
cout<<"������  �x  �u�w�t�u�s�}    ��  �u�s�}�u�t  �u�r�{"<<endl;
cout<<"������  �r  �r  �r�r�|�w    ��  �r�|�w�|�w�}�r  �r"<<endl<<endl;


    int ch;

    cout<<"                    ";
    SetColor(240);
    cout<< " �C���}�l " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " �W�h���� "  <<endl<<endl<< flush;
    cout<<"                    ";
    cout<< " ���}�C�� "  <<endl<< flush;
int updown = 0; //�W�U���m�ܼ�
    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){     //�W�U�䱱��
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
            cout<<"�����ߢz�s�{�z�w�{�s�w�{  �����ߢs�w�{�z�w�{�s�z�w"<<endl;
cout<<"������  �x  �u�w�t�u�s�}    ��  �u�s�}�u�t  �u�r�{"<<endl;
cout<<"������  �r  �r  �r�r�|�w    ��  �r�|�w�|�w�}�r  �r"<<endl<<endl;
    cout<<"                    ";  //space*20
        SetColor(240);
    cout<< " �C���}�l " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " �W�h���� " <<endl<<endl<< flush;
    cout<<"                    ";
    cout<< " ���}�C�� "  <<endl<< flush;
    break;

    case 1 :
        system("cls");
            cout<<"�����ߢz�s�{�z�w�{�s�w�{  �����ߢs�w�{�z�w�{�s�z�w"<<endl;
cout<<"������  �x  �u�w�t�u�s�}    ��  �u�s�}�u�t  �u�r�{"<<endl;
cout<<"������  �r  �r  �r�r�|�w    ��  �r�|�w�|�w�}�r  �r"<<endl<<endl;
        SetColor();
        cout<<"                    ";
    cout<< " �C���}�l " <<endl<<endl<< flush;
    cout<<"                    ";
    SetColor(240);
    cout<< " �W�h���� " <<endl<<endl<< flush;
    SetColor();
    cout<<"                    ";
    cout<< " ���}�C�� "  <<endl<< flush;
    break;

    case 2 :
        system("cls");
            cout<<"�����ߢz�s�{�z�w�{�s�w�{  �����ߢs�w�{�z�w�{�s�z�w"<<endl;
cout<<"������  �x  �u�w�t�u�s�}    ��  �u�s�}�u�t  �u�r�{"<<endl;
cout<<"������  �r  �r  �r�r�|�w    ��  �r�|�w�|�w�}�r  �r"<<endl<<endl;
        SetColor();
        cout<<"                    ";
    cout<< " �C���}�l " <<endl<<endl<< flush;;
    SetColor();
    cout<<"                    ";
    cout<< " �W�h���� " <<endl<<endl<< flush;
    cout<<"                    ";
    SetColor(240);
    cout<< " ���}�C�� "  <<endl<< flush;
    SetColor();
    break;

      }
          } // if(13)��

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
