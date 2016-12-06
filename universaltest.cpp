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
        cout<<"�{�b�����"<<xx+1<<"�쪱�a"<<endl;
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

