#ifndef TREM_H
#define TREM_H
#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int,pthread_mutex_t*); // construtor
    void run();                         // função a ser executada pela thread
    void setVelocidade(int);        // função chamada quando há mudança nos sliders


//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   pthread_mutex_t *regioes; // Ponteiro para o array de regioes criticas
};

#endif // TREM_H
