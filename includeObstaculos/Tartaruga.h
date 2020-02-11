#pragma once
#include "Obstaculo.h"
namespace Obstaculos
{
    class Tartaruga : public Obstaculo
    {
    public:
        Tartaruga(int x, int y);
        ~Tartaruga();

        void inicializa();
        void animacao();
        void update();

    };
}


