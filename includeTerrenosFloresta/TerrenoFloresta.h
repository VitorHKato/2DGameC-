#pragma once
#include "../Terreno.h"

namespace TerrenosFloresta
{
    class TerrenoFloresta : public Terreno
    {
    private:

    public:
        TerrenoFloresta(int x, int y, bool wall);
        ~TerrenoFloresta();

        void inicializa();
        void update();
        void animacao();
    };
}
