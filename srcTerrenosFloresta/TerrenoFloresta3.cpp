#include "../includeTerrenosFloresta/TerrenoFloresta3.h"
using namespace TerrenosFloresta;
TerrenoFloresta3::TerrenoFloresta3(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoFloresta3::~TerrenoFloresta3()
{

}
void TerrenoFloresta3::inicializa()
{
    loadSprite("imagens/F1Forest/blocos floresta.png");
    sprite.setTextureRect(IntRect(202, 0, 51, 50));
    sprite.setPosition(getPosicao());
}
void TerrenoFloresta3::update()
{

}
void TerrenoFloresta3::animacao()
{

}



