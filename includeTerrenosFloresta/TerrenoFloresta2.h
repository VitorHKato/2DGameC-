#pragma once
#include "../Terreno.h"

namespace TerrenosFloresta
{
    class TerrenoFloresta2 : public Terreno
    {
    private:

    public:
        TerrenoFloresta2(int x, int y, bool wall);
        ~TerrenoFloresta2();

        void inicializa();
        void update();
        void animacao();
    };
}
