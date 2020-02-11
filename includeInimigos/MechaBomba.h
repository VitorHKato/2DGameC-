#pragma once
#include "Inimigo.h"

namespace Inimigos
{
    class MechaBomba : public Inimigo
    {
    private:

    public:
        MechaBomba(int x, int y);
        ~MechaBomba();

        void inicializa();
        void animacao();
        void update();

        void setMorreu();
    };
}

