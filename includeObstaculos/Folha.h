#pragma once
#include "Obstaculo.h"
#include "../Personagem.h"

namespace Obstaculos
{
    class Folha : public Obstaculo
    {
    private:
        JogadorUm *playerOne;
        JogadorDois* playerTwo;
    public:
        Folha(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Folha();

        void inicializa();
        void animacao();
        void update();
    };
}
