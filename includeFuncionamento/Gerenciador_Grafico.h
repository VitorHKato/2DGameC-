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
        View view;                                  ///Classe SFML para fazer a movimentação da tela
        Event event;                                ///Classe SFML para identificar eventos únicos (ex: pulo)
        ListaEntidades* listaEntidades;             ///Associacao (Gerenciador_Grafico acessa metodos da ListaEntidades)
        ///Variáveis fixas -> Dimensões da janela
        static const float HEIGHT;
        static const float WIDTH;
        Mecanismo* mec;                             ///Associacao com o Mecanismo
        RenderWindow* window;                       ///Associacao com o RenderWindow
        Controle* control;                          ///Associação com Controle
        Menu* menu;                                 ///Associação com Menu
        JogadorUm* playerOne;                       ///Associação com playerOne
        JogadorDois* playerTwo;                     ///Associação com playerTwo
        bool pause;
        bool fase;                                  ///Identifica fase selecionada através do menu

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

        void loopPrincipal();               ///Loop infinito, identifica eventos, comandos, colisões e atualiza as imagens
        void update();                      ///Atualiza as imagens
        void pausar();                      ///Identifica pause no jogo (P)
        void tela();                        ///Faz a movimentacao da tela, conforme avanço dos personagens
    };
}
