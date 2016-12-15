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

int dice(),ChooseDice1(),ChooseDice2(),InBlack(),YesNo(),GameStart(),Rule(),TruePosition(int),Attack(int),FirstBase(int,int),SecondBase(int,int),ThirdBase(int,int),Energy(int),Body(int);
int result1,result2,sum;
string DiceNumber,name[4];
int position[3][10]; // it's mean whose star

void SetColor(int color = 7)  //����C��禡
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
        int z;  //z loop number(���)
        bool BlackHole; //�O�_�b�¬}



        /*position[]=800
          800�O������l���A
          8 �L�N�q
          0 �N���ݩ�֪�   1 2 3 4 ���O�ݩ�4�Ӫ��a
          0 �N��X����a   0 1 2 ���O�N����
          810 811 812 �ݩ�player1*/

        /*BlackHole
          0��� false �S���b�¬}
          1��� true ���b�¬}*/


};

struct  Drama1{  //�P�t1�@��
        string a0 = "�P�t1�P�y1";
        string a1 = "�P�t1�P�y2";
        string a2 = "�P�t1�P�y3";
        string a3 = "�P�t1�P�y4";
        string a4 = "�P�t1�P�y5";
        string a5 = "�P�t1�P�y6";
        string a6 = "�P�t1�P�y7";
        string a7 = "�P�t1�P�y8";
        string a8 = "�P�t1�P�y9";
        string a9 = "�P�t1�P�y10";
        string a10 = "�P�t1�P�y11";
        string a11 = "�P�t1�P�y12";
        string a12 = "�P�t1�P�y13";
        string a13 = "�P�t1�P�y14";
        string a14 = "�P�t1�P�y15";
        string a15 = "�P�t1�P�y16";
        string a16 = "�P�t1�P�y17";
        string a17 = "�P�t1�P�y18";
        string a18 = "�P�t1�P�y19";
        string a19 = "�P�t1�P�y20";
};
struct  Drama2{  //�P�t2�@��
        string b0 = "�P�t2�P�y1";
        string b1 = "�P�t2�P�y2";
        string b2 = "�P�t2�P�y3";
        string b3 = "�P�t2�P�y4";
        string b4 = "�P�t2�P�y5";
        string b5 = "�P�t2�P�y6";
        string b6 = "�P�t2�P�y7";
        string b7 = "�P�t2�P�y8";
        string b8 = "�P�t2�P�y9";
        string b9 = "�P�t2�P�y10";
        string b10 = "�P�t2�P�y11";
        string b11 = "�P�t2�P�y12";
        string b12 = "�P�t2�P�y13";
        string b13 = "�P�t2�P�y14";
        string b14 = "�P�t2�P�y15";
        string b15 = "�P�t2�P�y16";
        string b16 = "�P�t2�P�y17";
        string b17 = "�P�t2�P�y18";
        string b18 = "�P�t2�P�y19";
        string b19 = "�P�t2�P�y20";
};
struct  Drama3{  //�P�t3�@��
        string c0 = "�P�t3�P�y1";
        string c1 = "�P�t3�P�y2";
        string c2 = "�P�t3�P�y3";
        string c3 = "�P�t3�P�y4";
        string c4 = "�P�t3�P�y5";
        string c5 = "�P�t3�P�y6";
        string c6 = "�P�t3�P�y7";
        string c7 = "�P�t3�P�y8";
        string c8 = "�P�t3�P�y9";
        string c9 = "�P�t3�P�y10";
        string c10 = "�P�t3�P�y11";
        string c11 = "�P�t3�P�y12";
        string c12 = "�P�t3�P�y13";
        string c13 = "�P�t3�P�y14";
        string c14 = "�P�t3�P�y15";
        string c15 = "�P�t3�P�y16";
        string c16 = "�P�t3�P�y17";
        string c17 = "�P�t3�P�y18";
        string c18 = "�P�t3�P�y19";
        string c19 = "�P�t3�P�y20";
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
               position[i][j] = 800;
                                }
                           }
                        }    // set up to 800


      // -----------------------up it's basic set up -------------------------------------------------------------------
int gamestart = GameStart();   //���o�}�l�ƾ�

    if(gamestart==3){   //�}�l�C��

      system("cls");
      cout<<endl<<"�г]�w���a1�W��:";  //�]�w���a�W��
      cin>>name[0]; cout<<endl;
      cout<<"�г]�w���a2�W��:";
      cin>>name[1]; cout<<endl;
      cout<<"�г]�w���a3�W��:";
      cin>>name[2]; cout<<endl;
      cout<<"�г]�w���a4�W��:";
      cin>>name[3]; cout<<endl;

    do{

      for(int xx=0;xx<4;xx++){
        system("cls");
        SetColor(14);
        cout<<"�{�b���� "<<xx+1<<" �����a : "<<name[xx]<<endl;
        SetColor();
        cout<<"Energy  ";    //show energy
        Energy(xx);
        cout<<play[xx].energy<<" Tons"<<endl;
        cout<<"Body    ";      // show body
        Body(xx);
        cout<<play[xx].body<<"%"<<endl;

        if(play[xx].BlackHole){  //���լO�_�b�¬}
           cout<<endl<<"*�z���Q�¬}�l�ޤ�,���Y�X�ۦP����l�I�ƥH�k��"<<endl<<endl;
        }else{
            cout<<endl<<"�z�{�b����m�O";
            TruePosition(xx);  //�T�w��m
            cout<<"��"<<play[xx].z+1<<"��"<<endl;
        }
            //����ܤ@����m
        ChooseDice1(); //�Y�X�Ĥ@����l
        ChooseDice2(); //�Y�X�ĤG����l
            //--------------------------------------------------
         if(play[xx].BlackHole){  //���լO�_�b�¬}
           play[xx].BlackHole = InBlack()-1;
            if(play[xx].BlackHole){
                cout<<"�z���k��¬}������,�N�~��Q������"<<endl<<endl;
            }else{
                cout<<"�z�w���\�k��¬}������,�N�Q�H���ǰe��t�~��ӬP�t���@"<<endl<<endl;
                int AshortName = 0;
                switch(play[xx].x){  //�H���ǰe�ܥt��P�t
                   case 0:
                       do{
                        AshortName = dice();
                        play[xx].x = AshortName-1;
                        cout<<play[xx].x;
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
        }else{  //�p���b�¬}��,�~�����{��
            sum = result1 + result2 ;
            play[xx].y = play[xx].y + sum;  //�[�W��l�樫�B��
            play[xx].energy = play[xx].energy - sum*2 ;
            if(play[xx].y>19){   //�W�L�@����k�s�B�[�W�@��έp
              play[xx].y = play[xx].y - 20;
              play[xx].z = play[xx].z+1;
            }
            if(play[xx].z>1){    //���W�L���� �i�J�¬}
              play[xx].BlackHole = 1;
              play[xx].y = 0;
              play[xx].z = 0;
              cout<<endl<<"�z�����ݦb���P�t�L�[,�Q�P�t���j�j���¬}������,�N�Ȱ����ʯ�O"<<endl;
            }else{
             //switch
               cout<<endl<<"�z����m���ʦ�";
               TruePosition(xx);  //�T�w��m
               cout<<endl;

               Attack(xx);
               cout<<endl;
            }
        }




        cout<<endl<<"�Y�N���U�Ӫ��a"<<endl;
        system("pause");
      }


    }while((play[0].energy!=0&&play[0].body!=0)&&(play[1].energy!=0&&play[1].body!=0)&&(play[2].energy!=0&&play[2].body!=0)&&(play[3].energy!=0&&play[3].body!=0));
    //�C������
      cout<<"The Game Over,winner is "; //winner
      return main();
    //�N�]�m���^���|���}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  } else if (gamestart==2){   //�W�h����
         Rule();
         system("PAUSE");
         system("cls");
         return main();
  } else {                    //���}�C��
      cout<<endl<<endl<<endl<<endl<<"                 ";
      SetColor(207);
     cout<<"�Y�N���}�C��....."<<endl;
      SetColor();

  }

}
//------------------------------------main up----------------------------------------------------

int ChooseDice1(){

    cout<<endl<<"�п�J���N�Ӧ���Y�X��1����l"<<endl;
      cin>>DiceNumber;
      result1=dice();
      cout<<"�Ĥ@����l��"<<result1<<endl;

}

int ChooseDice2(){

    cout<<endl<<"�ЦA��J���N�Ӧ���Y�X��2����l"<<endl;
      cin>>DiceNumber;
      result2=dice();
      cout<<"�ĤG����l��"<<result2<<endl;

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

int Energy(int xx){  //  energy~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     if(play[xx].energy>=500){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p��  ";}
else if(play[xx].energy>=487){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�n��  ";}
else if(play[xx].energy>=475){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p  ��  ";}
else if(play[xx].energy>=462){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�n  ��  ";}
else if(play[xx].energy>=450){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p    ��  ";}
else if(play[xx].energy>=437){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�n    ��  ";}
else if(play[xx].energy>=425){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p      ��  ";}
else if(play[xx].energy>=412){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�n      ��  ";}
else if(play[xx].energy>=400){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p        ��  ";}
else if(play[xx].energy>=387){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�n        ��  ";}
else if(play[xx].energy>=375){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p          ��  ";}
else if(play[xx].energy>=362){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�n          ��  ";}
else if(play[xx].energy>=350){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p            ��  ";}
else if(play[xx].energy>=337){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�n            ��  ";}
else if(play[xx].energy>=325){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p              ��  ";}
else if(play[xx].energy>=312){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�n              ��  ";}
else if(play[xx].energy>=300){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p                ��  ";}
else if(play[xx].energy>=287){cout<<"��p�p�p�p�p�p�p�p�p�p�p�n                ��  ";}
else if(play[xx].energy>=275){cout<<"��p�p�p�p�p�p�p�p�p�p�p                  ��  ";}
else if(play[xx].energy>=262){cout<<"��p�p�p�p�p�p�p�p�p�p�n                  ��  ";}
else if(play[xx].energy>=250){cout<<"��p�p�p�p�p�p�p�p�p�p                    ��  ";}
else if(play[xx].energy>=237){cout<<"��p�p�p�p�p�p�p�p�p�n                    ��  ";}
else if(play[xx].energy>=225){cout<<"��p�p�p�p�p�p�p�p�p                      ��  ";}
else if(play[xx].energy>=212){cout<<"��p�p�p�p�p�p�p�p�n                      ��  ";}
else if(play[xx].energy>=200){cout<<"��p�p�p�p�p�p�p�p                        ��  ";}
else if(play[xx].energy>=187){cout<<"��p�p�p�p�p�p�p�n                        ��  ";}
else if(play[xx].energy>=175){cout<<"��p�p�p�p�p�p�p                          ��  ";}
else if(play[xx].energy>=162){cout<<"��p�p�p�p�p�p�n                          ��  ";}
else if(play[xx].energy>=150){cout<<"��p�p�p�p�p�p                            ��  ";}
else if(play[xx].energy>=137){cout<<"��p�p�p�p�p�n                            ��  ";}
else if(play[xx].energy>=125){cout<<"��p�p�p�p�p                              ��  ";}
else if(play[xx].energy>=112){cout<<"��p�p�p�p�n                              ��  ";}
else if(play[xx].energy>=100){cout<<"��p�p�p�p                                ��  ";}
else if(play[xx].energy>=87 ){cout<<"��p�p�p�n                                ��  ";}
else if(play[xx].energy>=75 ){SetColor(12);
                              cout<<"��p�p�p                                  ��  ";SetColor();}
else if(play[xx].energy>=62 ){SetColor(12);
                              cout<<"��p�p�n                                  ��  ";SetColor();}
else if(play[xx].energy>=50 ){SetColor(12);
                              cout<<"��p�p                                    ��  ";SetColor();}
else if(play[xx].energy>=37 ){SetColor(12);
                              cout<<"��p�n                                    ��  ";SetColor();}
else if(play[xx].energy>=25 ){SetColor(12);
                              cout<<"��p                                      ��  ";SetColor();}
else if(play[xx].energy>=12 ){SetColor(12);
                              cout<<"��n                                      ��  ";SetColor();}

}

int Body(int xx){   //body~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(play[xx].body>=100){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p��  ";}
else if(play[xx].body>=95){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p  ��  ";}
else if(play[xx].body>=90){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p    ��  ";}
else if(play[xx].body>=85){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p      ��  ";}
else if(play[xx].body>=80){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p�p        ��  ";}
else if(play[xx].body>=75){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p�p          ��  ";}
else if(play[xx].body>=70){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p�p            ��  ";}
else if(play[xx].body>=65){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p�p              ��  ";}
else if(play[xx].body>=60){cout<<"��p�p�p�p�p�p�p�p�p�p�p�p                ��  ";}
else if(play[xx].body>=55){cout<<"��p�p�p�p�p�p�p�p�p�p�p                  ��  ";}
else if(play[xx].body>=50){cout<<"��p�p�p�p�p�p�p�p�p�p                    ��  ";}
else if(play[xx].body>=45){cout<<"��p�p�p�p�p�p�p�p�p                      ��  ";}
else if(play[xx].body>=40){cout<<"��p�p�p�p�p�p�p�p                        ��  ";}
else if(play[xx].body>=35){cout<<"��p�p�p�p�p�p�p                          ��  ";}
else if(play[xx].body>=30){cout<<"��p�p�p�p�p�p                            ��  ";}
else if(play[xx].body>=25){cout<<"��p�p�p�p�p                              ��  ";}
else if(play[xx].body>=20){cout<<"��p�p�p�p                                ��  ";}
else if(play[xx].body>=15){SetColor(13);
                           cout<<"��p�p�p                                  ��  ";SetColor();}
else if(play[xx].body>=10){SetColor(13);
                           cout<<"��p�p                                    ��  ";SetColor();}
else if(play[xx].body>=5 ){SetColor(13);
                           cout<<"��p                                      ��  ";SetColor();}

}

int InBlack(){
    //  �¬}�{��
        if(result1==result2){ //���ը�ӻ�l�O�_�@��
           return 1 ;
        }else{
           return 2 ;
        }
}

int YesNo(){  //���yes or no ���禡

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
          } // if(13)��

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
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
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
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
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
cout<<" _____ _____ _____ _____    _____ _____ _____ _____ "<<endl;
cout<<"|   __|_   _|  _  | __  |  |_   _| __  |   __|  |  |"<<endl;
cout<<"|__   | | | |     |    -|    | | |    -|   __|    -|"<<endl;
cout<<"|_____| |_| |__|__|__|__|    |_| |__|__|_____|__|__|"<<endl<<endl;
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

int Rule(){   //�b����J�W�h
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

    switch(play[xx].x){  //�����Ѧb���ӬP�t
            case 0:
                switch(play[xx].y){  //�b���Ѧb���Ӧ�m
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
        cout<<endl<<"�z��F�@�ӵL�H�P�y"<<endl;
        cout<<"�O�_�n�b���إ߰�a"<<endl<<endl;
        zA = YesNo();
        if(zA==77){ //no
              cout<<endl<<"�z���b���إ߰�a"<<endl;
        }else {//yes
              position[xA][yA] = position[xA][yA] + xx*10 ;
              cout<<endl<<"Successful Building �@���q��a"<<endl;
        }
    }else if(position[xA][yA]==810||position[xA][yA]==811||position[xA][yA]==812){   //�p�G���쪱�a1�@���q��a
        cout<<endl<<position[xA][yA]<<endl<<endl;
        if(xx==0){   //�p�G���a1��F���a1����a
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
        }else{  //��L���a���쪱�a1����a

        }

    }else if(position[xA][yA]==820||position[xA][yA]==821||position[xA][yA]==822){   //�p�G���쪱�a2�@���q��a
        cout<<endl<<position[xA][yA]<<endl<<endl;
        if(xx==1){   //�p�G���a2��F���a2����a
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
        }else{  //��L���a���쪱�a2����a

        }

    }else if(position[xA][yA]==830||position[xA][yA]==831||position[xA][yA]==832){   //�p�G���쪱�a3�@���q��a
        cout<<endl<<position[xA][yA]<<endl<<endl;
        if(xx==2){   //�p�G���a3��F���a3����a
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
        }else{  //��L���a���쪱�a3����a

        }

    }else if(position[xA][yA]==840||position[xA][yA]==841||position[xA][yA]==842){   //�p�G���쪱�a4�@���q��a
        cout<<endl<<position[xA][yA]<<endl<<endl;
        if(xx==4){   //�p�G���a4��F���a4����a
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
        }else{  //��L���a���쪱�a4����a

        }

    }
}

int FirstBase(int xA,int yA){
    int zA;
                cout<<"�O�_�ɯŰ�a���G���q��a"<<endl;
                zA = YesNo();
                 if(zA==77){ //no
                    cout<<endl<<"�z���ɯŰ�a"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    cout<<endl<<"���\�ɯŬ��ĤG���q��a"<<endl;
                }

}

int SecondBase(int xA,int yA){
    int zA;
                cout<<"�O�_�ɯŰ�a���T���q��a"<<endl;
                zA = YesNo();
                 if(zA==75){ //no
                    cout<<endl<<"�z���ɯŰ�a"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    cout<<endl<<"���\�ɯŬ��ĤT���q��a"<<endl;
                }

}

int ThirdBase(int xA,int yA){
                cout<<"�z����a�w�ɯŦ̰ܳ���,�b���i�״_����"<<endl;  //�^�_�ֳ\����Ū��


}




