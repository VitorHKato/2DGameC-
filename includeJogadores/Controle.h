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
        ///Associa��o com os 2 players
        JogadorUm* playerOne;
        JogadorDois* playerTwo;

    public:
        Controle();
        ~Controle();

        ///Links
        void setJogadorUm(JogadorUm* playerOne);
        void setJogadorDois(JogadorDois* playerTwo);

        void comandos(Event event);               ///Faz a leitura de eventos �nicos dos jogadores, (ex: pulo)
        void movimentacao();                      ///Faz a leitura e movimenta��o dos jogadores em tempo real

    };
}
