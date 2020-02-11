#pragma once
#include "Jogador.h"
namespace Jogadores
{
    class JogadorDois : public Jogador
    {
    private:

    public:
        JogadorDois(int x, int y);
        ~JogadorDois();

        void inicializa();
        void animacao();
    };
}
