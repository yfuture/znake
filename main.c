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

    c[0].corpo = '8';
    c[1].corpo = 'O';
    c[2].corpo = '0';
    c[3].corpo = '0';
    c[4].corpo = '0';
    COORD coord;
    coord.X = c[4].x_pos;
    coord.Y = c[4].y_pos;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%c", c[4].corpo);
    coord.X = c[3].x_pos;
    coord.Y = c[3].y_pos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%c", c[3].corpo);
    coord.X = c[2].x_pos;
    coord.Y = c[2].y_pos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%c", c[2].corpo);
    coord.X = c[1].x_pos;
    coord.Y = c[1].y_pos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%c", c[1].corpo);
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

