#pragma once
#include "../Terreno.h"

namespace TerrenosLabirinto
{
    class TerrenoLabirinto : public Terreno
    {
    private:

    public:
        TerrenoLabirinto(int x, int y, bool wall);
        ~TerrenoLabirinto();

        void inicializa();
        void update();
        void animacao();
    };
}

