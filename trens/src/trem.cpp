#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 50 && x < 620)
                x+=10;
            else if (x == 620 && y < 180)
                y+=10;
            else if (x > 450 && y == 180)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 50 && x < 790)
                x+=10;
            else if (x == 790 && y < 180)
                y+=10;
            else if (x > 620 && y == 180)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 180 && x < 530)
                x+=10;
            else if (x == 530 && y < 330)
                y+=10;
            else if (x > 340 && y == 330)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 180 && x < 710)
                x+=10;
            else if(x == 710 && y < 330)
                y+=10;
            else if (x > 530 && y == 330)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 180 && x < 940)
                x+=10;
            else if(x == 940 && y < 330)
                y+=10;
            else if (x > 710 && y == 330)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




