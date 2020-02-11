#include "../includeTerrenosFloresta/TerrenoFloresta.h"
using namespace TerrenosFloresta;
TerrenoFloresta::TerrenoFloresta(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(100, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoFloresta::~TerrenoFloresta()
{

}
void TerrenoFloresta::inicializa()
{
    loadSprite("imagens/F1Forest/blocos floresta.png");
    sprite.setTextureRect(IntRect(50, 0, 101, 50));
    sprite.setPosition(getPosicao());
}
void TerrenoFloresta::update()
{

}
void TerrenoFloresta::animacao()
{

}

