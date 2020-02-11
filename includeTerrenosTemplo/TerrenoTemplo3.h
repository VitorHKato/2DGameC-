#pragma once
#include "../Terreno.h"

namespace TerrenosTemplo
{
    class TerrenoTemplo3 : public Terreno
    {
    private:

    public:
        TerrenoTemplo3(int x, int y, bool wall);
        ~TerrenoTemplo3();

        void inicializa();
        void update();
        void animacao();
    };
}



