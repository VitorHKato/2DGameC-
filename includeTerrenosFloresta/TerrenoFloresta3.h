#pragma once
#include "../Terreno.h"

namespace TerrenosFloresta
{
    class TerrenoFloresta3 : public Terreno
    {
    private:

    public:
        TerrenoFloresta3(int x, int y, bool wall);
        ~TerrenoFloresta3();

        void inicializa();
        void update();
        void animacao();
    };
}

