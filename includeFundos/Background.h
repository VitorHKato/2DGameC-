#pragma once
#include "../Entidade.h"

namespace Fundos
{
    class Background : public Entidade
    {
    public:
        Background(int x, int y, const char* arq);
        ~Background();

        void update();
        void inicializa();
        void animacao();
    };
}
