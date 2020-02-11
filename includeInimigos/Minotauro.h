#pragma once
#include "Inimigo.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeJogadores/JogadorUm.h"
using namespace Jogadores;

namespace Inimigos
{
    class Minotauro : public Inimigo
    {
    private:
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
        bool bravo;
        int vidas;
    public:
        Minotauro(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Minotauro();

        void inicializa();
        void animacao();
        void animacaoBravo();
        void update();
    };
}


