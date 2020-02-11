#pragma once
#include "Jogador.h"
namespace Jogadores
{
    class JogadorUm : public Jogador
    {
    private:

    public:
        JogadorUm(int x, int y);
        ~JogadorUm();

        void inicializa();
        void animacao();
    };
}

