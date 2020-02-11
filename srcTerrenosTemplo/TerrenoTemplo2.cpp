#include "../includeTerrenosTemplo/TerrenoTemplo2.h"
using namespace TerrenosTemplo;
TerrenoTemplo2::TerrenoTemplo2(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoTemplo2::~TerrenoTemplo2()
{

}
void TerrenoTemplo2::inicializa()
{
    loadSprite("imagens/F3Temple/blocos templo.png");
    sprite.setTextureRect(IntRect(104, 54, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoTemplo2::update()
{

}
void TerrenoTemplo2::animacao()
{

}





