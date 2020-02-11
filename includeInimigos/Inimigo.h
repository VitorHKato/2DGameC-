#pragma once
#include "../Personagem.h"

namespace Inimigos
{
    class Inimigo : public Personagem
    {
    public:
        Inimigo(int x, int y);
        ~Inimigo();

    };
}
