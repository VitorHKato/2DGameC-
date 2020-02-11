#pragma once
#include "Obstaculo.h"
namespace Obstaculos
{
    class Fogo : public Obstaculo
    {
    public:
        Fogo(int x, int y);
        ~Fogo();

        void inicializa();
        void animacao();
        void update();

    };
}

