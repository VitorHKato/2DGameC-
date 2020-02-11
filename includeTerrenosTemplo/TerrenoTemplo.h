#pragma once
#include "../Terreno.h"

namespace TerrenosTemplo
{
    class TerrenoTemplo : public Terreno
    {
    private:

    public:
        TerrenoTemplo(int x, int y, bool wall);
        ~TerrenoTemplo();

        void inicializa();
        void update();
        void animacao();
    };
}

