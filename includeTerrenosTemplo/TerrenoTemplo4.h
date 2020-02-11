#pragma once
#include "../Terreno.h"

namespace TerrenosTemplo
{
    class TerrenoTemplo4 : public Terreno
    {
    private:

    public:
        TerrenoTemplo4(int x, int y, bool wall);
        ~TerrenoTemplo4();

        void inicializa();
        void update();
        void animacao();
    };
}




