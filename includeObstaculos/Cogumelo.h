#pragma once
#include "Obstaculo.h"
namespace Obstaculos
{
    class Cogumelo : public Obstaculo
    {
    private:
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
    public:
        Cogumelo(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Cogumelo();

        void inicializa();
        void animacao();
        void update();

    };
}
