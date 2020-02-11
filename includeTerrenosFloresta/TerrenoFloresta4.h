#pragma once
#include "../Terreno.h"

namespace TerrenosFloresta
{
    class TerrenoFloresta4 : public Terreno
    {
    private:

    public:
        TerrenoFloresta4(int x, int y, bool wall);
        ~TerrenoFloresta4();

        void inicializa();
        void update();
        void animacao();
    };
}
