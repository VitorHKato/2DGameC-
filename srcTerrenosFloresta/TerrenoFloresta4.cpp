#include "../includeTerrenosFloresta/TerrenoFloresta4.h"
using namespace TerrenosFloresta;
TerrenoFloresta4::TerrenoFloresta4(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(300, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoFloresta4::~TerrenoFloresta4()
{

}
void TerrenoFloresta4::inicializa()
{
    loadSprite("imagens/F1Forest/blocos floresta.png");
    sprite.setTextureRect(IntRect(0, 51, 301, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoFloresta4::update()
{

}
void TerrenoFloresta4::animacao()
{

}



