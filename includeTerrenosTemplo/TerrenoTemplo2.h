#pragma once
#include "../Terreno.h"

namespace TerrenosTemplo
{
    class TerrenoTemplo2 : public Terreno
    {
    private:

    public:
        TerrenoTemplo2(int x, int y, bool wall);
        ~TerrenoTemplo2();

        void inicializa();
        void update();
        void animacao();
    };
}


