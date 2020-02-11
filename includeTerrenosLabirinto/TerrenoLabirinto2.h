#pragma once
#include "../Terreno.h"

namespace TerrenosLabirinto
{
    class TerrenoLabirinto2 : public Terreno
    {
    private:

    public:
        TerrenoLabirinto2(int x, int y, bool wall);
        ~TerrenoLabirinto2();

        void inicializa();
        void update();
        void animacao();
    };
}

