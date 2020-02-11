#pragma once
#include "Inimigo.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeJogadores/JogadorUm.h"
using namespace Jogadores;

namespace Inimigos
{
    class TorradaZombie : public Inimigo
    {
    private:
        int contadorCorrer;                                 ///Contador para a torrada dar uma "deslizada rapida"
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
    public:
        TorradaZombie(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~TorradaZombie();

        void inicializa();
        void animacao();
        void animacaoBravo();
        void update();
    };
}




