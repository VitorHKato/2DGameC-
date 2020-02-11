// Classe Principal
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeFases/Floresta.h"
#include "../includeFases/Labirinto.h"
#include "../includeListas/ListaEntidades.h"
#include "../includeFuncionamento/Mecanismo.h"
#include "../includeJogadores/Controle.h"
#include "../includeFases/Templo.h"
#include "../includeFuncionamento/Menu.h"
using namespace std;
using namespace sf;
using namespace Jogadores;
using namespace Fases;
using namespace Funcionamento;

namespace Funcionamento
{
    class Jogo
    {
    private:
        RenderWindow* window;                            ///Janela de reproducao do jogo, classe da biblioteca SFML

        ///Composições
        Gerenciador_Grafico* gerenciador;
        ListaEntidades* listaEntidades;
        JogadorUm* playerOne;
        JogadorDois* playerTwo;
        Mecanismo* mec;
        Floresta* faseUmFloresta;
        Labirinto* faseDoisLabirinto;
        Templo* faseTresTemplo;
        Controle* control;

        Menu* menu;

    public:
        Jogo();
        ~Jogo();
        void inicializa();          ///Faz a alocação de memória das classes
        void relacoes();            ///Realiza as relações entre classes
        void janela();              ///Inicializa o atributo window
    };
}

