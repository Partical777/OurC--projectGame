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
int position[3][20],Tool[4]; // it's mean whose star  &  �D��ƭ�
                             // �D��bmain���]�ߪ�l��
                             // �p���ʶR�ӹD�� �h0�|�ܬ�1

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
        string a0 = "�Ӫů�";
        string a1 = "�P�t1�P�y2";
        string a2 = "�P�t1�P�y3";
        string a3 = "�P�t1�P�y4";
        string a4 = "�P�t1�P�y5";
        string a5 = "�ά}";
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
        string b11 = "�ά}";
        string b12 = "�P�t2�P�y13";
        string b13 = "�P�t2�P�y14";
        string b14 = "�P�t2�P�y15";
        string b15 = "�P�ڽ��";
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
        string c9 = "�ө�";
        string c10 = "�P�t3�P�y11";
        string c11 = "�P�t3�P�y12";
        string c12 = "�P�t3�P�y13";
        string c13 = "�P�t3�P�y14";
        string c14 = "�P�t3�P�y15";
        string c15 = "�P�t3�P�y16";
        string c16 = "�P�t3�P�y17";
        string c17 = "�ά}";
        string c18 = "�P�t3�P�y19";
        string c19 = "�P�t3�P�y20";
};
struct story{    //��}�l���@��
    string story0 = "������������������������������������������������������������������������������\n��";
	string story1 = "���ѩ�a�y�Y�N�����A�|��j�I�ά��F�ͦs�A��O�L�̨M�w�b�a�y�H�~���P�y�A      ��\n��";
	string story2 = "���إߦۤv���ޥ��a�C���O�L�̭n�X�o�h���ܦۤv���ޥ��a�ɡA�L�̲��ͤF�E�P�Ĭ�A��\n��";
    string story3 = "���֤]�����֡A��O�L�̨M�w�U�̦ۤv���O�q�A�h���ܦۤv����a�A���������۩��ӡA��\n��";
    string story4 = "���N�o�˶}�l�F�E�P���A���ڹ�......                                          ��\n��";
    string story5 = "������������������������������������������������������������������������������\n";
 };
struct Player play[] = {
       {5000,100,0,0,0,0},  //player1  use play[0]
       {5000,100,0,0,0,0},  //player2  use play[1]
       {5000,100,0,0,0,0},  //player3  use play[2]
       {5000,100,0,0,0,0},  //player4  use play[3]
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
               Tool[k]=8000000;  //�o�O�D���l��

               play[k].energy = 5000;
               play[k].body = 100 ;
               play[k].x = 0 ;
               play[k].y = 0 ;
               play[k].z = 0 ;
               play[k].BlackHole = 0 ;
                        }    // set up to 800
               system("cls");


      // -----------------------up it's basic set up -------------------------------------------------------------------
int gamestart = GameStart();   //���o�}�l�ƾ�

    if(gamestart==3){   //�}�l�C��
      struct story pass ;

      system("cls");     //��ܼ@��
      cout<<pass.story0<<"                                                                          ��"<<endl;
      cout<<pass.story1<<"                                                                          ��"<<endl;
      cout<<pass.story2<<"                                                                          ��"<<endl;
      cout<<pass.story3<<"                                                                          ��"<<endl;
      cout<<pass.story4<<"                                                                          ��"<<endl;
      cout<<pass.story5;
      system("pause");

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
        SetColor(color[xx]);
        cout<<"�{�b���� "<<xx+1<<" �����a : "<<name[xx]<<endl;
        SetColor();
        cout<<"Energy  ";    //show energy
        Energy(xx);
        cout<<play[xx].energy<<" Tons"<<endl;
        cout<<"Body    ";      // show body
        Body(xx);
        cout<<play[xx].body<<"%"<<endl;
        xxglobal = xx ;
        Map();
        if(play[xx].BlackHole){  //���լO�_�b�¬}
           cout<<"�z���b��"<<play[xx].x+1<<"�P�t"<<endl<<"*���Q�¬}�l�ޤ�,���Y�X�ۦP����l�I�ƥH�k��"<<endl<<endl;
        }else{
            cout<<endl<<"��"<<play[xx].z+1<<"��"<<"   ";
            cout<<"�z�{�b����m�O"<<endl;
            TruePositionOnlyName(xx);  //�T�w��m
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
              if(play[xx].x==0){   //�p�G�b�Ĥ@�P�t�g�L�Ӫů��|�^�_100TONS�෽
              play[xx].energy = play[xx].energy + 100;
               }
            }
            if(play[xx].z>1){    //���W�L���� �i�J�¬}
              play[xx].BlackHole = 1;
              play[xx].y = 0;
              play[xx].z = 0;
              cout<<endl<<"�z�����ݦb���P�t�L�[,�Q�P�t���j�j���¬}������,�N�Ȱ����ʯ�O"<<endl;
            }else{  //------------------�S�b�¬}�B�S�]�W�L���i�J�¬}
             //switch
               cout<<endl<<"�z����m���ʦ�";
               int temporary = play[xx].x ;
               TruePosition(xx);  //�T�w��m
               cout<<endl;


               SuddenlyEvent(xx);   //��o�ƥ�
               Alien(xx);   //�~�P�H�ƥ�

         if(temporary-play[xx].x==0){  //�p�G�g�L�ά}��N���b����
               if(play[xx].x==0){
                  if(play[xx].y==0){            //�p�G���O1-1
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




        cout<<endl<<"�Y�N���U�Ӫ��a"<<endl;
        system("pause");
      }


    }while((play[0].energy>0&&play[0].body>0)&&(play[1].energy>0&&play[1].body>0)&&(play[2].energy>0&&play[2].body>0)&&(play[3].energy>0&&play[3].body>0));
    //�C������
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
      cout<<"The Game Over,loser is "<<loser<<endl; //winner
      cout<<"�п�J���N����"<<endl;
      cin>>loser ;
      system("pause");
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
else if(play[xx].energy>0 ){SetColor(0);
                              cout<<"��k                                      ��  ";SetColor();}

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
else if(play[xx].body>0 ){SetColor(13);
                           cout<<"��k                                      ��  ";SetColor();}

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

    switch(play[xx].x){  //�����Ѧb���ӬP�t
            case 0:
                switch(play[xx].y){  //�b���Ѧb���Ӧ�m
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
                  case 15: cout<<drama2.b15 ;//���
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
        cout<<"�O�_�n����50Tons�b���إ߰�a"<<endl<<endl;
        zA = YesNo();
        if(zA==77){ //no
              cout<<endl<<"�z���b���إ߰�a"<<endl;
        }else {//yes
              position[xA][yA] = position[xA][yA] + (xx+1)*10 ;
              play[xx].energy = play[xx].energy - 50 ;
              cout<<endl<<"Successful Building �@���q��a"<<endl;
              cout<<"Energy ��֤F 50 Tons " <<endl;
        }
    }else if(position[xA][yA]==810||position[xA][yA]==811||position[xA][yA]==812){   //�p�G���쪱�a1�@���q��a

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

         switch(position[xA][yA]){
            case 810:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[0]<<" ���@���q��a"<<endl<<"�D���������m�]�I����!"<<endl<<"Energy���10 Tons  ,  Body���l2%"<<endl<<name[0]<<" ��Energy �W�[10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[0].energy = play[0].energy + 10;
                }
                HowManyTool(xx);  //�O�_�m�U��誺��a

                switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 811:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[0]<<" ���G���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���20 Tons  ,  Body���l4%"<<endl<<name[0]<<" ��Energy �W�[20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[0].energy = play[0].energy + 20;
                }
                HowManyTool(xx);  //�O�_�m�U��誺��a

                switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 810;

                break;
                }

                break;
            case 812:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[0]<<" ���T���q��a"<<endl<<"�D���������m�]�I����!!!"<<endl<<"Energy���50 Tons  ,  Body���l8%"<<endl<<name[0]<<" ��Energy �W�[50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[0].energy = play[0].energy + 50;
                }
                HowManyTool(xx);  //�O�_�m�U��誺��a

                switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 810;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 811;

                break;
                }

                break;
         }    //switch
        }

    }else if(position[xA][yA]==820||position[xA][yA]==821||position[xA][yA]==822){   //�p�G���쪱�a2�@���q��a

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

          switch(position[xA][yA]){
            case 820:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[1]<<" ���@���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���10 Tons  ,  Body���l2%"<<endl<<name[1]<<" ��Energy �W�[10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[1].energy = play[1].energy + 10;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 821:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[1]<<" ���G���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���20 Tons  ,  Body���l4%"<<endl<<name[1]<<" ��Energy �W�[20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[1].energy = play[1].energy + 20;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 820;

                break;
                }

                break;
            case 822:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[1]<<" ���T���q��a"<<endl<<"�D���������m�]�I����!!!"<<endl<<"Energy���50 Tons  ,  Body���l8%"<<endl<<name[1]<<" ��Energy �W�[50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[1].energy = play[1].energy + 50;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 820;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 821;

                break;
                }

                break;
         }    //switch

        }

    }else if(position[xA][yA]==830||position[xA][yA]==831||position[xA][yA]==832){   //�p�G���쪱�a3�@���q��a

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

          switch(position[xA][yA]){
            case 830:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[2]<<" ���@���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���10 Tons  ,  Body���l2%"<<endl<<name[2]<<" ��Energy �W�[10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[2].energy = play[2].energy + 10;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 831:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[2]<<" ���G���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���20 Tons  ,  Body���l4%"<<endl<<name[2]<<" ��Energy �W�[20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[2].energy = play[2].energy + 20;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 830;

                break;
                }

                break;
            case 832:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[2]<<" ���T���q��a"<<endl<<"�D���������m�]�I����!!!"<<endl<<"Energy���50 Tons  ,  Body���l8%"<<endl<<name[2]<<" ��Energy �W�[50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[2].energy = play[2].energy + 50;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 830;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 831;

                break;
                }

                break;
         }    //switch

        }

    }else if(position[xA][yA]==840||position[xA][yA]==841||position[xA][yA]==842){   //�p�G���쪱�a4�@���q��a

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

          switch(position[xA][yA]){
            case 840:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[3]<<" ���@���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���10 Tons  ,  Body���l2%"<<endl<<name[3]<<" ��Energy �W�[10 Tons";
          play[xx].energy = play[xx].energy - 10;
          play[xx].body = play[xx].body - 2 ;
          play[3].energy = play[3].energy + 10;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 800;

                break;
                }

                break;
            case 841:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[3]<<" ���G���q��a"<<endl<<"�D���������m�]�I����!!"<<endl<<"Energy���20 Tons  ,  Body���l4%"<<endl<<name[3]<<" ��Energy �W�[20 Tons";
          play[xx].energy = play[xx].energy - 20;
          play[xx].body = play[xx].body - 4 ;
          play[3].energy = play[3].energy + 20;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 800;

                break;
                case 5 :     //���C1��
                    position[xA][yA] = 840;

                break;
                }

                break;
            case 842:
                UcantSeeMe(xx);
                if(skill!=1){  //�K������
                cout<<"�z�{�b���� "<<name[3]<<" ���T���q��a"<<endl<<"�D���������m�]�I����!!!"<<endl<<"Energy���50 Tons  ,  Body���l8%"<<endl<<name[3]<<" ��Energy �W�[50 Tons";
          play[xx].energy = play[xx].energy - 50;
          play[xx].body = play[xx].body - 8 ;
          play[3].energy = play[3].energy + 50;
                     }
                     HowManyTool(xx);  //�O�_�m�U��誺��a

                     switch(skill){  //��ܹD��
                case 2 :
                    switch(xx){   //������a
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
                case 3 :     //������a
                    position[xA][yA] = 800;

                break;
                case 4 :     //���C2��
                    position[xA][yA] = 840;

                break;
                case 5 :     //���C1��
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
                cout<<"�O�_����80Tons�ӤɯŰ�a���G���q��a"<<endl;
                zA = YesNo();
                 if(zA==77){ //no
                    cout<<endl<<"�z���ɯŰ�a"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    play[xx].energy = play[xx].energy - 80 ;
                    cout<<endl<<"���\�ɯŬ��ĤG���q��a"<<endl;
                    cout<<"Energy ��֤F 80 Tons " <<endl;
                }

}

int SecondBase(int xA,int yA){
    int zA;
    int xx = xxglobal;
                cout<<"�O�_����150Tons�ɯŰ�a���T���q��a"<<endl;
                zA = YesNo();
                 if(zA==75){ //no
                    cout<<endl<<"�z���ɯŰ�a"<<endl;
                }else {//yes
                    position[xA][yA] = position[xA][yA]+1 ;
                    play[xx].energy = play[xx].energy - 150 ;
                    cout<<endl<<"���\�ɯŬ��ĤT���q��a"<<endl;
                    cout<<"Energy ��֤F 150 Tons " <<endl;
                }

}

int ThirdBase(int xA,int yA){
                cout<<"�z����a�w�ɯŦ̰ܳ���,�b���i�״_����"<<endl;  //�^�_�ֳ\����Ū��


}

int Map(){
    int yy = play[xxglobal].x ;
    string StarNameInMap[20];
    switch(yy){   // ��ܦa�ϰ�
  case 0:
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
    cout<<"                                      "<<"��"<<endl;  //1
    cout<<"                                      "<<StarNameInMap[0]<<endl<<endl;  //1
    SetColor();

    BaseColor(yy,19);
    cout<<"                               ";
    Stage(yy,19);  SetColor();                                 //20
    BaseColor(yy,1);
    cout<<"            ";
    Stage(yy,1);
    cout<<endl;   SetColor();                                 //2

    BaseColor(yy,19);
    cout<<"                               "<<"��"<<"      ";  SetColor();   //20
    BaseColor(yy,1);
    cout<<"      "<<"��"<<"              "<<endl;             SetColor();    //2`
    BaseColor(yy,19);
    cout<<"                               "<<StarNameInMap[19]<<"      ";SetColor();  //20
    BaseColor(yy,1);
    cout<<"       "<<StarNameInMap[1]<<"              "<<endl<<endl;    SetColor();//2

    BaseColor(yy,18);
    cout<<"                          ";
    Stage(yy,18);  SetColor();                                 //19
    BaseColor(yy,2);
    cout<<"                      ";
    Stage(yy,2);
    cout<<endl;   SetColor();                                 //3

    BaseColor(yy,18);
    cout<<"                          "<<"��"<<"          ";    SetColor();//19
    BaseColor(yy,2);
    cout<<"            "<<"��"<<"              "<<endl;        SetColor();//3
    BaseColor(yy,18);
    cout<<"                          "<<StarNameInMap[18]<<"          ";  SetColor();  //19
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
    cout<<"                    "<<"��"<<"            ";          SetColor(); //18
    BaseColor(yy,3);
    cout<<"                      "<<"��"<<"     "<<endl;         SetColor(); //4
    BaseColor(yy,17);
    cout<<"                    "<<StarNameInMap[17]<<"            ";        SetColor();   //18
    BaseColor(yy,3);
    cout<<"                      "<<StarNameInMap[3]<<"     "<<endl<<endl; SetColor(); //4

    BaseColor(yy,16);
    cout<<"               ";
    Stage(yy,16);  SetColor();                                 //17
    BaseColor(yy,4);
    cout<<"                                             ";
    Stage(yy,4);
    cout<<endl;   SetColor();                                 //5

    BaseColor(yy,16);
    cout<<"               "<<"��"<<"                   ";           SetColor(); //17
    BaseColor(yy,4);
    cout<<"                          "<<"��"<<"     "<<endl;        SetColor();//5
    BaseColor(yy,16);
    cout<<"               "<<StarNameInMap[16]<<"                   ";         SetColor();//17
    BaseColor(yy,4);
    cout<<"                          "<<StarNameInMap[4]<<"     "<<endl<<endl;SetColor();  //5

    BaseColor(yy,15);
    cout<<"          ";
    Stage(yy,15);  SetColor();                                 //16
    BaseColor(yy,5);
    cout<<"                                                       ";
    Stage(yy,5);
    cout<<endl;   SetColor();                                 //6

    BaseColor(yy,15);
    cout<<"          "<<"��"<<"                        ";                 SetColor(); //16
    BaseColor(yy,5);
    cout<<"                               "<<"��"<<"     "<<endl;         SetColor();  //6
    BaseColor(yy,15);
    cout<<"          "<<StarNameInMap[15]<<"                        ";               SetColor();//16
    BaseColor(yy,5);
    cout<<"                               "<<StarNameInMap[5]<<"     "<<endl<<endl; SetColor(); //6

    BaseColor(yy,14);
    cout<<"      ";
    Stage(yy,14);  SetColor();                                 //15
    BaseColor(yy,6);
    cout<<"                                                                ";
    Stage(yy,6);
    cout<<endl;   SetColor();                                 //7

    BaseColor(yy,14);
    cout<<"      "<<"��"<<"                             ";                    SetColor();//15
    BaseColor(yy,6);
    cout<<"                                   "<<"��"<<"     "<<endl;         SetColor();//7
    BaseColor(yy,14);
    cout<<"      "<<StarNameInMap[14]<<"                             ";                  SetColor();//15
    BaseColor(yy,6);
    cout<<"                                   "<<StarNameInMap[6]<<"     "<<endl<<endl; SetColor(); //7

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
    cout<<" "<<"��"<<"          ";  SetColor(); //14
    BaseColor(yy,12);
    cout<<"��"<<"           ";  SetColor(); //13
    BaseColor(yy,11);
    cout<<"��"<<"           ";  SetColor(); //12
    BaseColor(yy,10);
    cout<<"��"<<"           ";  SetColor(); //11
    BaseColor(yy,9);
    cout<<"��"<<"           ";  SetColor(); //10
    BaseColor(yy,8);
    cout<<"��"<<"          ";  SetColor(); //9
    BaseColor(yy,7);
    cout<<"��"<<"           "<<endl; SetColor();  //8
    BaseColor(yy,13);
    cout<<" "<<StarNameInMap[13]<<"          ";  SetColor(); //14
    BaseColor(yy,12);
    cout<<StarNameInMap[12]<<"           ";  SetColor(); //13
    BaseColor(yy,11);
    cout<<StarNameInMap[11]<<"           ";  SetColor(); //12
    BaseColor(yy,10);
    cout<<StarNameInMap[10]<<"           ";  SetColor(); //11
    BaseColor(yy,9);
    cout<<StarNameInMap[9]<<"           ";  SetColor(); //10
    BaseColor(yy,8);
    cout<<StarNameInMap[8]<<"            ";  SetColor(); //9
    BaseColor(yy,7);
    cout<<StarNameInMap[7]<<"           "<<endl<<endl;  SetColor(); //8

}

int BaseColor(int a,int b){    //�]�m������C��

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

int Stage(int a,int b){    //�]�m���q��a
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

int Bet(){     //  ����j���
    cout<<"�z�Ө�F�P�ڽ���A�N�i�H�ϥί෽�@���w�X�A�H������h�෽"<<endl<<endl;
    int latech = 0;
    cout<<"�п�ܹC��"<<endl;
    cout<<"�q�Ʀr�i��o�T���෽�A��j�p�i��o�⭿�෽"<<endl;
    latech = ChooseGame();
    if(latech==77){   //right's
        BigSmall();
    }else{
        GuessNumber();
    }

}

int ChooseGame(){//��ܹC�������@�MYesNo()�@��
    int ch;
    int lastch;
    SetColor(240);

    cout<< "\r �q�Ʀr " ;
    SetColor();
    cout<< " ��j�p "  << flush;

    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){
    case 75 :
    SetColor(240);
    cout<< "\r �q�Ʀr " ;
    SetColor();
    cout<< " ��j�p " << flush ;
    lastch = 75;
    break;

    case 77 :
    SetColor();
    cout<< "\r �q�Ʀr " ;
    SetColor(240);
    cout<< " ��j�p " << flush ;
    SetColor();
    lastch = 77;
    break;

      }
          } // if(13)��

    }while(ch!=13);
       return lastch;

}

int GuessNumber(){     //�q�Ʀr
    int betmoney = 0;
    int result123456789 = 0;
    int betnumber = 0;
    do{
    cout<<endl<<"�п�J����կ෽�ƶq : ";
    cin>>betmoney;
    }while(betmoney>play[xxglobal].energy);


    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%5)+1};
    }
    result123456789 = random[rand()%10000];

    cout<<endl<<"�п�J���@�Ʀr1~5�A�p�q���Y�i��o�෽�T�������y"<<endl;
    do{
    cin>>betnumber;
    }while(betnumber>5||betnumber<1);

    if(betnumber==result123456789){
        play[xxglobal].energy = play[xxglobal].energy + betmoney*2 ;

        //------------------�p��ӥi�~����
        cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
        cout<<"������ӡI�I"<<endl;

          cout<<"�O�_�~�� �q�Ʀr���෽"<<endl;     //�O�_�~����
          result123456789 = YesNo();       //result123456789 ���ƨϥ�
          if(result123456789==77){ //no
              cout<<endl<<"�N���}�P�ڽ��"<<endl;
             }else {//yes
              GuessNumber();
             }
         //----------------------------------------

    }else{
        play[xxglobal].energy = play[xxglobal].energy - betmoney ;
        cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
        cout<<"�z���B�𤣦n�A�q���F�A�ЦA���A�F"<<endl;

    }

    cout<<"�O�_�~�� �q�Ʀr���෽"<<endl;     //�O�_�~����
    result123456789 = YesNo();       //result123456789 ���ƨϥ�
    if(result123456789==77){ //no
              cout<<endl<<"�N���}�P�ڽ��"<<endl;
        }else {//yes
              GuessNumber();
        }

}

int BigSmall(){   //��j�p
    int betmoney = 0;
    int result123456789 = 0;
    int betnumber = 0;
    do{
    cout<<endl<<"�п�J����կ෽�ƶq : ";
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

    cout<< "\r ��j " ;
    SetColor();
    cout<< " ��p "  << flush;

    do{
       ch=getch();
       if(ch==224){
          ch=getch();

    switch(ch){
    case 75 :
    SetColor(240);
    cout<< "\r ��j " ;
    SetColor();
    cout<< " ��p " << flush ;
    lastch = 75;
    break;

    case 77 :
    SetColor();
    cout<< "\r ��j " ;
    SetColor(240);
    cout<< " ��p " << flush ;
    SetColor();
    lastch = 77;
    break;

      }
          } // if(13)��

    }while(ch!=13);


    cout<<endl<<"�п�J���@�Ʀr1~20�A�p����ӧQ�i��o�G�������y"<<endl;
    do{
    cin>>betnumber;
    }while(betnumber>20||betnumber<1);


    if(lastch==77){   //��p

         if(betnumber<result123456789){
         play[xxglobal].energy = play[xxglobal].energy + betmoney ;
         cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
         cout<<"������ӡI�I"<<endl;

         //----------------�p��ӥi�~����
          cout<<"�O�_�~�� ��j�p���෽"<<endl;     //�O�_�~����
          result123456789 = YesNo();       //result123456789 ���ƨϥ�
          if(result123456789==77){ //no
              cout<<endl<<"�N���}�P�ڽ��"<<endl;
          }else {//yes
              GuessNumber();
          }
        //--------------------------------

         }else{
         play[xxglobal].energy = play[xxglobal].energy - betmoney ;
         cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
         cout<<"�z���B�𤣦n�A�q���F�A�ЦA���A�F"<<endl;
    }

    }else{           //��j

        if(betnumber>result123456789){
        play[xxglobal].energy = play[xxglobal].energy + betmoney ;
        cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
        cout<<"������ӡI�I"<<endl;
        //----------------�p��ӥi�~����
          cout<<"�O�_�~�� ��j�p���෽"<<endl;     //�O�_�~����
          result123456789 = YesNo();       //result123456789 ���ƨϥ�
          if(result123456789==77){ //no
              cout<<endl<<"�N���}�P�ڽ��"<<endl;
          }else {//yes
              GuessNumber();
          }
        //--------------------------------
        }else{
        play[xxglobal].energy = play[xxglobal].energy - betmoney ;
        cout<<"���a���Ʀr��"<<result123456789<<","<<"�z���Ʀr��"<<betnumber<<endl;
        cout<<"�z���B�𤣦n�A�q���F�A�ЦA���A�F"<<endl;
    }

    }



}

int Wormhole(int xx){         //�ά}�禡
    int AshortSystem = 0;
                switch(play[xx].x){  //��ܶǰe�ܥt��P�t
                   case 0:
                       do{
                        cout<<endl<<"�п�J���e���P�t�A���F�Ĥ@�P�t�~"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x <= 0||play[xx].x>2);
                       play[xx].y = 0 ;

                    break;
                   case 1:
                       do{
                        cout<<endl<<"�п�J���e���P�t�A���F�ĤG�P�t�~"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x == 1||play[xx].x<0||play[xx].x>2);
                       play[xx].y = 0 ;

                    break;
                   case 2:
                       do{
                        cout<<endl<<"�п�J���e���P�t�A���F�ĤT�P�t�~"<<endl;
                        cin>>AshortSystem;
                        play[xx].x = AshortSystem-1;
                       }while(play[xx].x >=2||play[xx].x<0);
                       play[xx].y = 0 ;

                    break;
                }
                play[xx].energy = play[xx].energy - 15 ;
                cout<<"Success moving !"<<endl;
}


int SuddenlyEvent(int xx){    // ��o�ƥ�{��
    //  �H���{��
    int result;
    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%20)+1};
    }
    result = random[rand()%10000];

    if(result==7){   //�Ѧ�5%�����vĲ�o�ƥ�


        //�ƥ�a�ɦ��h�֭� �@���H������


    }
}

int Alien(int xx){       //��o�J��~�P�H
    //  �H���{��
    int result;
    srand(time(NULL));
     int random[10000];
    for(int i=0;i<10000;i++)
    {
        random[i]={(rand()%40)+1};
    }
    result = random[rand()%10000];

    if(result==35){   //�Ѧ�2.5%�����vĲ�o�ƥ�
         for(int i=0;i<10000;i++)
        {
           random[i]={(rand()%2)+1};
        }
        result = random[rand()%10000];    //�b�H�����X1/2�����v�I��n�����a���~�P�H

        if(result==1){   //�p�G�I��n��
        //�~�P�H�ƥ�
        }else{           //�p�G�I���a��
        //�~�P�H�ƥ�
        }
    }

}

int Store(int xx){  //�T�w6��
       int s = Tool[xx];
       int num[6];
       int toolchoose = 0;

       cout<<"�w��Ө�t�z�K�Q��"<<endl<<"�o�̦��ܦh�D����A���"<<endl;

       for(int z = 0; z<6 ;z++){   //���Ѥw����عD�� ���X�C�@���
         num[z] = s%10;
         s = s/10 ;
       }

       //   80 0 0 0 0 0    �q�᭱�}�l��
       //    5 4 3 2 1 0 ��

       if(s!=8000000){    //�p�G���D��

       cout<<"�z�ثe����";
       // �p�G���U�C�D��
       if(num[0]==1){cout<<"�^�_���� ";}
       if(num[1]==1){cout<<"�������� ";}
       if(num[2]==1){cout<<"�b�J�P�� ";}
       if(num[3]==1){cout<<"���P Death Star ";}
       if(num[4]==1){cout<<"�ּu ";}
       if(num[5]==1){cout<<"�q�ϯ߽� ";}
       }



       cout<<endl<<"�i�ʶR�D�㶵��,�p�w�ʶR�����رN���A�W�["<<endl;
       cout<<"1.�^�_����((�ί෽�����m����   2.��������((�K������"<<endl<<"3.�b�J�P��((�������a   4.���P Death Star((��������a"<<endl<<"5.�ּu((���C�G����a   6.�q�ϯ߽�((���C�@����a   7. Cancel"<<endl;
       cout<<"�п�ܱz�Q�ʶR�D�㤧�s���A�@�^�X�u���ʶR�@��"<<endl;
       do{
            cin>>toolchoose;
       }while(toolchoose>7||toolchoose<1);

       toolchoose = toolchoose - 1 ;

       switch(toolchoose){
       case 0 : play[xx].energy = play[xx].energy - 100;
                play[xx].body = play[xx].body + 10;
                cout<<endl<<"success buying �^�_����10%"<<endl;
                break;                                                 //�^�_����
       case 1 : if (num[0]==1){Tool[xx] = Tool[xx]+10;play[xx].energy = play[xx].energy - 40 ;cout<<endl<<"success buying ��������"<<endl;}; break;        //��������
       case 2 : if (num[0]==1){Tool[xx] = Tool[xx]+100;play[xx].energy = play[xx].energy - 100 ;cout<<endl<<"success buying �b�J�P��"<<endl;}; break;       //�b�J�P��
       case 3 : if (num[0]==1){Tool[xx] = Tool[xx]+1000;play[xx].energy = play[xx].energy - 75 ;cout<<endl<<"success buying ���P Death Star"<<endl;}; break;      //���P Death Star
       case 4 : if (num[0]==1){Tool[xx] = Tool[xx]+10000;play[xx].energy = play[xx].energy - 50 ;cout<<endl<<"success buying �ּu"<<endl;}; break;     //�ּu
       case 5 : if (num[0]==1){Tool[xx] = Tool[xx]+100000;play[xx].energy = play[xx].energy - 25 ;cout<<endl<<"success buying �q�ϯ߽�"<<endl;}; break;    //�q�ϯ߽�

       }
}

int UcantSeeMe(int xx){
       int s = Tool[xx];
       int num[6];

       for(int z = 0; z<6 ;z++){   //���Ѥw����عD�� ���X�C�@���
         num[z] = s%10;
         s = s/10 ;
       }
       //   80 0 0 0 0 0    �q�᭱�}�l��
       //    5 4 3 2 1 0 ��

       if(num[1]==1){    //�p�G���D��

       cout<<endl<<endl<<"�z�ثe����:";
       // �p�G���U�C�D��
       //if(num[0]==1){cout<<"1.�^�_���� ";}
       cout<<"1.��������";
/*     if(num[2]==1){cout<<"2.�b�J�P�� ";}
       if(num[3]==1){cout<<"3.���P Death Star ";}
       if(num[4]==1){cout<<"4.�ּu ";}
       if(num[5]==1){cout<<"5.�q�ϯ߽� ";}
  */
       cout<<endl<<"�O�_�ϥΥ�������,�p�n�ϥνЫ�1,�p���ϥνЫ� 6 "<<endl;
       do{
       cin>>skill;
       }while(skill!=1||skill!=6);
       if(skill==1){
        Tool[xx] = Tool[xx] - 10;
        cout<<"���\���L��誺������"<<endl;
       }

       }


}


int HowManyTool(int xx){
       int s = Tool[xx];
       int num[6];

       for(int z = 0; z<6 ;z++){   //���Ѥw����عD�� ���X�C�@���
         num[z] = s%10;
         s = s/10 ;
       }

       //   80 0 0 0 0 0    �q�᭱�}�l��
       //    5 4 3 2 1 0 ��

       if(Tool[xx]!=8000000&&Tool[xx]!=8000010){    //�p�G���D��

       cout<<"�z�ثe����:";
       // �p�G���U�C�D��
       //if(num[0]==1){cout<<"1.�^�_���� ";}
       //if(num[1]==1){cout<<"1.�������� ";}
       if(num[2]==1){
            cout<<"2.�b�J�P�� ";
       }
       if(num[3]==1){
            cout<<"3.���P Death Star ";
            }
       if(num[4]==1){
            cout<<"4.�ּu ";
       }
       if(num[5]==1){
            cout<<"5.�q�ϯ߽� ";
       }

       cout<<endl<<"�п�ܨϥιD��A�p���ϥνЫ� 6 "<<endl;
       do{
       cin>>skill;
       }while(skill>6||skill<2);

         switch(skill){
        case 2:
            if(num[2]==1){
        cout<<endl<<"�w�ϥ� �b�J�P�� , ���ڤF����a,�ܬ��ڤ�}�a"<<endl;
        Tool[xx] = Tool[xx]-100;
            }else{
              cout<<"�A�õL�����D��,���������ϥ�"<<endl;
            }
        break;
        case 3:
            if(num[3]==1){
        cout<<endl<<"���P Death Star , �w�N�Ĥ���v�}�a�p��,�^�k�L�H�P�y"<<endl;
        Tool[xx] = Tool[xx]-1000;
            }else{
              cout<<"�A�õL�����D��,���������ϥ�"<<endl;
            }
        break;
        case 4:
            if(num[4]==1){
        cout<<endl<<"�ּu , �w���Ĥ�l���G��,���C�G����a"<<endl;
        Tool[xx] = Tool[xx]-10000;
            }else{
              cout<<"�A�õL�����D��,���������ϥ�"<<endl;
            }
        break;
        case 5:
            if(num[5]==1){
        cout<<endl<<"�q�ϯ߽� , �w���Ĥ�D���ǳ\���l,���C�@����a"<<endl;
        Tool[xx] = Tool[xx]-100000;
            }else{
              cout<<"�A�õL�����D��,���������ϥ�"<<endl;
            }
        break;


         }

    }


}
