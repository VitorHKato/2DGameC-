#include "../includeTerrenosTemplo/TerrenoTemplo.h"
using namespace TerrenosTemplo;
TerrenoTemplo::TerrenoTemplo(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(100, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoTemplo::~TerrenoTemplo()
{

}
void TerrenoTemplo::inicializa()
{
    loadSprite("imagens/F3Temple/blocos templo.png");
    sprite.setTextureRect(IntRect(0, 0, 101, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoTemplo::update()
{

}
void TerrenoTemplo::animacao()
{

}




