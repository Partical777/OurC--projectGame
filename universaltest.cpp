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

int dice(),ChooseDice1(),ChooseDice2(),InBlack(),YesNo();
int result1,result2,sum;
string DiceNumber;

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
        int position[3][10]; // it's mean whose star


        /*position[]=800
          800�O������l���A
          8 �L�N�q
          0 �N��X����a   1 2 3 ���O�N����
          0 �N���ݩ�֪�   1 2 3 4 �����ݩ�4�Ӫ��a*/
        /*BlackHole
          0��� false �S���b�¬}
          1��� true ���b�¬}*/

};

struct  Drama1{  //�P�t1�@��
        string a0 = "what the fuck1";
        string a1 = "what the shit2";
        string a2 = "what the fuck3";
        string a3 = "what the shit4";
        string a4 = "what the fuck5";
        string a5 = "what the shit6";
        string a6 = "what the fuck";
        string a7 = "what the shit";
        string a8 = "what the fuck";
        string a9 = "what the shit";
        string a10 = "what the fuck";
        string a11 = "what the shit";
        string a12 = "what the fuck";
        string a13= "what the shit";
        string a14= "what the fuck";
        string a15 = "what the shit";
        string a16 = "what the fuck";
        string a17 = "what the shit";
        string a18 = "what the fuck";
        string a19 = "what the shit";
};
struct  Drama2{  //�P�t2�@��
        string b0 = "what the fuck1";
        string b1 = "what the shit2";
        string b2 = "what the fuck3";
        string b3 = "what the shit4";
        string b4 = "what the fuck5";
        string b5 = "what the shit6";
        string b6 = "what the fuck";
        string b7 = "what the shit";
        string b8 = "what the fuck";
        string b9 = "what the shit";
        string b10 = "what the fuck";
        string b11 = "what the shit";
        string b12 = "what the fuck";
        string b13= "what the shit";
        string b14= "what the fuck";
        string b15 = "what the shit";
        string b16 = "what the fuck";
        string b17 = "what the shit";
        string b18 = "what the fuck";
        string b19 = "what the shit";
};
struct  Drama3{  //�P�t3�@��
        string c0 = "what the fuck1";
        string c1 = "what the shit2";
        string c2 = "what the fuck3";
        string c3 = "what the shit4";
        string c4 = "what the fuck5";
        string c5 = "what the shit6";
        string c6 = "what the fuck";
        string c7 = "what the shit";
        string c8 = "what the fuck";
        string c9 = "what the shit";
        string c10 = "what the fuck";
        string c11 = "what the shit";
        string c12 = "what the fuck";
        string c13= "what the shit";
        string c14= "what the fuck";
        string c15 = "what the shit";
        string c16 = "what the fuck";
        string c17 = "what the shit";
        string c18 = "what the fuck";
        string c19 = "what the shit";
};
//---------------------------------------main----------------------------------------------------------------------------------
int main(){
     struct Drama1 drama1;
     struct Drama2 drama2;
     struct Drama3 drama3;
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
        SetColor(14);
        cout<<"�{�b����� "<<xx+1<<" �쪱�a"<<endl;
        SetColor();

        if(play[xx].BlackHole){  //���լO�_�b�¬}
           cout<<endl<<"*�z���Q�¬}�l�ޤ�,���Y�X�ۦP����l�I�ƥH�k��"<<endl<<endl;
        }
        ChooseDice1(); //�Y�X�Ĥ@����l
        ChooseDice2(); //�Y�X�ĤG����l
            //--------------------------------------------------
         if(play[xx].BlackHole){  //���լO�_�b�¬}
           play[xx].BlackHole = InBlack()-1;
            if(play[xx].BlackHole){
                cout<<"�z�w���\�k��¬}������,�N�Q�H���ǰe��t�~��ӬP�t���@"<<endl<<endl;
            }else{
                cout<<"�z���k��¬}������,�N�~��Q������"<<endl<<endl;
            }
            //--------------------------------------------------
        }else{  //�p���b�¬}��,�~�����{��
            sum = result1 + result2 ;
            play[xx].y = play[xx].y + sum;  //�[�W��l�樫�B��
            if(play[xx].y>20){   //�W�L�@����k�s�B�[�W�@��έp
              play[xx].y = play[xx].y - 20;
              play[xx].z = play[xx].z+1;
            }
            if(play[xx].z>1){    //���W�L���� �i�J�¬}
              play[xx].BlackHole = 1;
              play[xx].y = 0;
              play[xx].z = 0;
              cout<<"�z�����ݦb���P�t�L�[,�Q�P�t���j�j���¬}������,�N�Ȱ����ʯ�O"<<endl;
            }

            switch(play[xx].x){  //�����Ѧb���ӬP�t
            case 0:
                switch(play[xx].y){  //�b���Ѧb���Ӧ�m
                  case 0: cout<<drama1.a0<<endl ;break;
                  case 1: cout<<drama1.a1<<endl ;break;
                  case 2: cout<<drama1.a2<<endl ;break;
                  case 3: cout<<drama1.a3<<endl ;break;
                  case 4: cout<<drama1.a4<<endl ;break;
                  case 5: cout<<drama1.a5<<endl ;break;
                  case 6: cout<<drama1.a6<<endl ;break;
                  case 7: cout<<drama1.a7<<endl ;break;
                  case 8: cout<<drama1.a8<<endl ;break;
                  case 9: cout<<drama1.a9<<endl ;break;
                  case 10: cout<<drama1.a10<<endl ;break;
                  case 11: cout<<drama1.a11<<endl ;break;
                  case 12: cout<<drama1.a12<<endl ;break;
                  case 13: cout<<drama1.a13<<endl ;break;
                  case 14: cout<<drama1.a14<<endl ;break;
                  case 15: cout<<drama1.a15<<endl ;break;
                  case 16: cout<<drama1.a16<<endl ;break;
                  case 17: cout<<drama1.a17<<endl ;break;
                  case 18: cout<<drama1.a18<<endl ;break;
                  case 19: cout<<drama1.a19<<endl ;break;

                }
                break;

            case 1:
                switch(play[xx].y){
                  case 0: cout<<drama2.b0<<endl ;break;
                  case 1: cout<<drama2.b1<<endl ;break;
                  case 2: cout<<drama2.b2<<endl ;break;
                  case 3: cout<<drama2.b3<<endl ;break;
                  case 4: cout<<drama2.b4<<endl ;break;
                  case 5: cout<<drama2.b5<<endl ;break;
                  case 6: cout<<drama2.b6<<endl ;break;
                  case 7: cout<<drama2.b7<<endl ;break;
                  case 8: cout<<drama2.b8<<endl ;break;
                  case 9: cout<<drama2.b9<<endl ;break;
                  case 10: cout<<drama2.b10<<endl ;break;
                  case 11: cout<<drama2.b11<<endl ;break;
                  case 12: cout<<drama2.b12<<endl ;break;
                  case 13: cout<<drama2.b13<<endl ;break;
                  case 14: cout<<drama2.b14<<endl ;break;
                  case 15: cout<<drama2.b15<<endl ;break;
                  case 16: cout<<drama2.b16<<endl ;break;
                  case 17: cout<<drama2.b17<<endl ;break;
                  case 18: cout<<drama2.b18<<endl ;break;
                  case 19: cout<<drama2.b19<<endl ;break;

                }
                break;

            case 2:
                switch(play[xx].y){
                  case 0: cout<<drama3.c0<<endl ;break;
                  case 1: cout<<drama3.c1<<endl ;break;
                  case 2: cout<<drama3.c2<<endl ;break;
                  case 3: cout<<drama3.c3<<endl ;break;
                  case 4: cout<<drama3.c4<<endl ;break;
                  case 5: cout<<drama3.c5<<endl ;break;
                  case 6: cout<<drama3.c6<<endl ;break;
                  case 7: cout<<drama3.c7<<endl ;break;
                  case 8: cout<<drama3.c8<<endl ;break;
                  case 9: cout<<drama3.c9<<endl ;break;
                  case 10: cout<<drama3.c10<<endl ;break;
                  case 11: cout<<drama3.c11<<endl ;break;
                  case 12: cout<<drama3.c12<<endl ;break;
                  case 13: cout<<drama3.c13<<endl ;break;
                  case 14: cout<<drama3.c14<<endl ;break;
                  case 15: cout<<drama3.c15<<endl ;break;
                  case 16: cout<<drama3.c16<<endl ;break;
                  case 17: cout<<drama3.c17<<endl ;break;
                  case 18: cout<<drama3.c18<<endl ;break;
                  case 19: cout<<drama3.c19<<endl ;break;

                }
                break;

            }
        }

        cout<<endl<<"�Y�N���U�Ӫ��a"<<endl;
        system("pause");
      }

      cout<<play[0].energy<<play[0].x<<play[0].y<<play[0].position[0][0]<<result1<<result2<<endl;

    }while((play[0].energy!=0&&play[0].body!=0)&&(play[1].energy!=0&&play[1].body!=0)&&(play[2].energy!=0&&play[2].body!=0)&&(play[3].energy!=0&&play[3].body!=0));

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
