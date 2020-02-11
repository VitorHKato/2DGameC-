#include "../includeTerrenosTemplo/TerrenoTemplo4.h"
using namespace TerrenosTemplo;
TerrenoTemplo4::TerrenoTemplo4(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoTemplo4::~TerrenoTemplo4()
{

}
void TerrenoTemplo4::inicializa()
{
    loadSprite("imagens/F3Temple/blocos templo.png");
    sprite.setTextureRect(IntRect(158, 54, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoTemplo4::update()
{

}
void TerrenoTemplo4::animacao()
{

}






