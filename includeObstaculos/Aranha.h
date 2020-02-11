#pragma once
#include "../includeObstaculos/Obstaculo.h"
namespace Obstaculos
{
    class Aranha : public Obstaculo
    {
    private:
        int contador;
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
    public:
        Aranha(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Aranha();

        void inicializa();
        void animacao();
        void update();

    };
}

