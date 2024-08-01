#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <conio2.h>
#include <unistd.h>

int run = 1;
char key;
int direcao, num = 4;
struct Cobra{int x_pos, y_pos; char corpo;} c[100];
struct Fruta{int x_pos, y_pos;} f;

void Teclado(){

        printf("%c%d\n", key, direcao);
        
        if(direcao==0){printf("up             ^\n");};
        if(direcao==1){printf("down           v\n");};
        if(direcao==2){printf("rigth           >\n");};
        if(direcao==3){printf("left          <\n");};        
        printf("xpos%d\t yposx%d\n", c[0].x_pos, c[0].y_pos);

};

int Pos_Co(){

    for (int i=num;i>0;--i){
       
        c[i].x_pos=c[i-1].x_pos;
        c[i].y_pos=c[i-1].y_pos;

    };

    //limites da tela
    if(c[0].x_pos <= 1){c[0].x_pos = 1;};
    if(c[0].x_pos >= 80){c[0].x_pos = 80;};
    if(c[0].y_pos <= 1){c[0].y_pos = 1;};
    if(c[0].y_pos >= 80){c[0].y_pos = 80;};

    //direcao
    if(direcao==0){c[0].y_pos-=1;};
    if(direcao==1){c[0].y_pos+=1;};
    if(direcao==2){c[0].x_pos+=1;};
    if(direcao==3){c[0].x_pos-=1;};
             
};

int Draw(){
    //desenha a figura
    //printf("\033[0;10m %i", c[0]);

    //c[0].corpo = 'O';
    //c[1].corpo = '0';
    //c[2].corpo = '0';
    //c[3].corpo = '0';
    //c[4].corpo = '0';
    COORD coord;

    for(int a = 0; a < 10; a ++){
        c[a].corpo = '@';
        coord.X = c[a].x_pos;
        coord.Y = c[a].y_pos;
        printf("%c", c[a].corpo);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        
    };
};

void SetBackgroundColor(int backcolor){

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD wColor = ((backcolor & 0x0F) << 4) + (csbi.wAttributes & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);

};

int main(){

    SetBackgroundColor(3);

    //loop
    while(run==1){

        Draw();

        //keyboard detections
        int hit = kbhit();
        if(hit){
            char key = getch();
            if(key=='w'){direcao=0;};
            if(key=='s'){direcao=1;};
            if(key=='d'){direcao=2;};
            if(key=='a'){direcao=3;};
            if(key=='p'){printf("   :)  jogo pausado!\n"); system("pause");};
        };

        //run+=1;
        
        Pos_Co();
        system("cls");
    };
    
    system("pause");

}

