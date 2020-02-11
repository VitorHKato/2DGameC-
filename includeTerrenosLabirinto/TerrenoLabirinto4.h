#pragma once
#include "../Terreno.h"

namespace TerrenosLabirinto
{
    class TerrenoLabirinto4 : public Terreno
    {
    private:

    public:
        TerrenoLabirinto4(int x, int y, bool wall);
        ~TerrenoLabirinto4();

        void inicializa();
        void update();
        void animacao();
    };
}



