#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

namespace Funcionamento
{
    class Menu
    {
    private:
        ///Fundo
        Texture textura;
        Sprite imagem;
        ///Textos
        Font fonte;
        Text menu0;
        Text menu1;
        Text menu2;
        Text menu3;
        Text menu4;

        int menu;                   ///op��o
        bool ativo;                 ///Se ainda � foi escolhida uma op��o

    public:
        Menu();
        ~Menu();
        int menuPrincipal(RenderWindow* App);
        int menuFases(RenderWindow* App);

        void setAtivo(bool ativo);
        bool getAtivo();
    };
}
