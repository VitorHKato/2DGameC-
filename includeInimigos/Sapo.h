#pragma once
#include "Inimigo.h"
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
using namespace Jogadores;

namespace Inimigos
{
    class Sapo : public Inimigo
    {
    private:
        int contJump;
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
    public:
        Sapo(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Sapo();

        void inicializa();
        void animacao();
        void update();
    };
}




