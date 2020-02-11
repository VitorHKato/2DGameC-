#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
using namespace sf;
namespace Jogadores
{
    class Controle
    {
    private:
        ///Associação com os 2 players
        JogadorUm* playerOne;
        JogadorDois* playerTwo;

    public:
        Controle();
        ~Controle();

        ///Links
        void setJogadorUm(JogadorUm* playerOne);
        void setJogadorDois(JogadorDois* playerTwo);

        void comandos(Event event);               ///Faz a leitura de eventos únicos dos jogadores, (ex: pulo)
        void movimentacao();                      ///Faz a leitura e movimentação dos jogadores em tempo real

    };
}
