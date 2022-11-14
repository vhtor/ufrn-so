#include <utility>
#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, pthread_mutex_t *mutex)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    regioes = mutex;
}

//Função a ser executada após executar trem->START
void Trem::run()
{
    while(true)
    {
        switch(ID)
        {
            //Trem 1
            case 1:
                if (y == 50 && x < 600) {
                    x+=10;
                }
                // Entrada na região crítica 0
                else if (y == 50 && x < 620) {
                    pthread_mutex_trylock(&regioes[0]);     // Bloqueia a região crítica 0 para evitar colisão com o trem 2
                    pthread_mutex_trylock(&regioes[2]);     // Bloqueia a região crítica 2 para evitar colisão com o trem 3 e 4
                    pthread_mutex_trylock(&regioes[1]);     // Bloqueia a região crítica 1 para evitar colisão com o trem 3
                    x+=10;
                }
                else if (y < 160 && x == 620) {
                    y+=10;
                }
                // Entrada na região crítica 2
                else if (x == 620 && y < 180) {
                    y+=10;
                }
                else if (y == 180 && x > 550) {
                    x-=10;
                }
                // Entrada na região crítica 1
                else if (y == 180 && x > 450) {
                    pthread_mutex_unlock(&regioes[0]);
                    x-=10;
                }
                else {
                    y-=10;
                    pthread_mutex_unlock(&regioes[1]);      // Libera a região 1 ao começar a subir
                    pthread_mutex_unlock(&regioes[2]);      // Libera a região 2 ao começar a subir
                }
                emit updateGUI(ID, x, y);    //Emite um sinal para atualizar a posição do trem na interface
                break;

            //Trem 2
            case 2:
                if (y == 50 && x < 790) {
                    x+=10;
                }
                else if (x == 790 && y < 160) {
                    y+=10;
                }
                // Entrada na região crítica 4
                else if (x == 790 && y < 180) {
                    y+=10;
                }
                // Andando na região crítica 4
                else if (y == 180 && x > 730) {
                    x-=10;
                }
                // Entrada na região crítica 3
                else if (y == 180 && x > 650) {
                    x-=10;
                }
                // Entrada na região crítica 0
                else if (y == 180 && x > 620) {
                    pthread_mutex_lock(&regioes[0]);        // Usar o lock faz o trem esperar até que a região seja desbloqueada para andar
                    x-=10;
                }
                else {
                    y-=10;
                }
                emit updateGUI(ID, x, y);    //Emite um sinal para atualizar a posição do trem na interface
                break;

            //Trem 3
            case 3:
                if (y == 180 && x < 450) {
                    x+=10;
                }
                else if (y == 180 && x < 500) {
                    x+=10;
                }
                // Entrada na região crítica 5
                else if (y == 180 && x < 530) {
                    x+=10;
                }
                // Andando na região crítica 5
                else if (x == 530 && y < 330) {
                    y+=10;
                }
                else if (x > 340 && y == 330) {
                    x-=10;
                }
                else if (x == 340 && y > 200) {
                    y-=10;
                }
                else if (x == 340 && y > 180) {
                    y-=10;
                }
                //emit updateGUI(ID, x, y);    //Emite um sinal para atualizar a posição do trem na interface
                break;

            //Trem 4
            case 4:
                // Região crítica 2
                if (y == 180 && x < 590) {
                    x+=10;
                }
                // Entrada na região crítica 3
                else if (y == 180 && x < 600) {
                    x+=10;
                }
                else if (y == 180 && x < 710) {
                    x+=10;
                }
                // Região crítica 6
                else if(x == 710 && y < 330) {
                    y+=10;
                }
                else if (x > 530 && y == 330) {
                    x-=10;
                }
                else if (y == 330 && x > 550) {
                    x-=10;
                }
                // Entrada na região crítica 5
                else if (y == 330 && x > 530) {
                    pthread_mutex_trylock(&regioes[5]);
                    x-=10;
                }
                // Andando na região crítica 5
                else {
                    y-=10;
                }
                //emit updateGUI(ID, x, y);    //Emite um sinal para atualizar a posição do trem na interface
                break;

            //Trem 5
            case 5:
                // Região crítica 4
                if (y == 180 && x < 790) {
                    x+=10;
                }
                else if (y == 180 && x < 940) {
                    x+=10;
                }
                else if(x == 940 && y < 330) {
                    y+=10;
                }
                else if (x > 710 && y == 330) {
                    x-=10;
                }
                // Região crítica 6
                else {
                    y-=10;
                }
                //emit updateGUI(ID, x, y);    //Emite um sinal para atualizar a posição do trem na interface
                break;

            default:
                break;
            }
        msleep(velocidade);
    }
}




