#pragma once
#include "../Personagem.h"

namespace Jogadores
{
    class Jogador : public Personagem
    {
    private:

    public:
        Jogador(int x, int y);
        ~Jogador();

        ///Como os 2 jogadores s�o id�nticos e apenas a textura muda, utiliz�o o mesmo update
        virtual void animacao() = 0;
        virtual void update();
    };
}

