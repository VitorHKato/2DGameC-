#pragma once
#include "Inimigo.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeJogadores/JogadorUm.h"
using namespace Jogadores;

namespace Inimigos
{
    class Morcego : public Inimigo
    {
    private:
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
        bool bravo;
        int contVoo;
        int distancia;
        bool morreu;
    public:
        Morcego(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Morcego();

        void inicializa();
        void animacao();
        void animacaoBravo();
        void update();

    };
}


