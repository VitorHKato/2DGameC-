#pragma once
#include "Inimigo.h"
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
using namespace Jogadores;

namespace Inimigos
{
    class Bomba : public Inimigo
    {
    private:
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
        bool acordou;
    public:
        Bomba(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo, bool olhandoDireita);
        ~Bomba();

        void inicializa();
        void animacao();
        void update();
    };
}
