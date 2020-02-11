#pragma once
#include "SFML/Graphics.hpp"
#include "../includeListas/ListaEntidades.h"
#include "../includeJogadores/Controle.h"
#include "../includeFuncionamento/Mecanismo.h"
#include "../includeFuncionamento/Menu.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeJogadores/JogadorUm.h"

using namespace sf;

namespace Funcionamento
{
    class Gerenciador_Grafico
    {
    private:
        View view;                                  ///Classe SFML para fazer a movimenta��o da tela
        Event event;                                ///Classe SFML para identificar eventos �nicos (ex: pulo)
        ListaEntidades* listaEntidades;             ///Associacao (Gerenciador_Grafico acessa metodos da ListaEntidades)
        ///Vari�veis fixas -> Dimens�es da janela
        static const float HEIGHT;
        static const float WIDTH;
        Mecanismo* mec;                             ///Associacao com o Mecanismo
        RenderWindow* window;                       ///Associacao com o RenderWindow
        Controle* control;                          ///Associa��o com Controle
        Menu* menu;                                 ///Associa��o com Menu
        JogadorUm* playerOne;                       ///Associa��o com playerOne
        JogadorDois* playerTwo;                     ///Associa��o com playerTwo
        bool pause;
        bool fase;                                  ///Identifica fase selecionada atrav�s do menu

    public:
        Gerenciador_Grafico(Menu* m);
        ~Gerenciador_Grafico();

        ///Links
        void setWindow(RenderWindow* window);
        void setListaEntidades(ListaEntidades* listaEntidades);
        void setMecanismo(Mecanismo* mec);
        void setControle(Controle* control);
        void setJogadorUm(JogadorUm* playerOne);
        void setJogadorDois(JogadorDois* playerTwo);

        static const float getHEIGHT();
        static const float getWIDTH();

        void loopPrincipal();               ///Loop infinito, identifica eventos, comandos, colis�es e atualiza as imagens
        void update();                      ///Atualiza as imagens
        void pausar();                      ///Identifica pause no jogo (P)
        void tela();                        ///Faz a movimentacao da tela, conforme avan�o dos personagens
    };
}
