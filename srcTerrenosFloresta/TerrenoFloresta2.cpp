#include "../includeTerrenosFloresta/TerrenoFloresta2.h"
using namespace TerrenosFloresta;
TerrenoFloresta2::TerrenoFloresta2(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoFloresta2::~TerrenoFloresta2()
{

}
void TerrenoFloresta2::inicializa()
{
    loadSprite("imagens/F1Forest/blocos floresta.png");
    sprite.setTextureRect(IntRect(151, 0, 51, 50));
    sprite.setPosition(getPosicao());
}
void TerrenoFloresta2::update()
{

}
void TerrenoFloresta2::animacao()
{

}


