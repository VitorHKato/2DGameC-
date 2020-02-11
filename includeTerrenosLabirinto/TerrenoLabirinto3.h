#pragma once
#include "../Terreno.h"

namespace TerrenosLabirinto
{
    class TerrenoLabirinto3 : public Terreno
    {
    private:

    public:
        TerrenoLabirinto3(int x, int y, bool wall);
        ~TerrenoLabirinto3();

        void inicializa();
        void update();
        void animacao();
    };
}


