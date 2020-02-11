#pragma once
#include "../Personagem.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeJogadores/JogadorUm.h"
using namespace Jogadores;

namespace Obstaculos
{
    class Obstaculo : public Personagem
    {

    public:
        Obstaculo(int x, int y);
        ~Obstaculo();
    };
}
