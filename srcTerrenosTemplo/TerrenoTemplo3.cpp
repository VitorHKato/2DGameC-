#include "../includeTerrenosTemplo/TerrenoTemplo3.h"
using namespace TerrenosTemplo;
TerrenoTemplo3::TerrenoTemplo3(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(100, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoTemplo3::~TerrenoTemplo3()
{

}
void TerrenoTemplo3::inicializa()
{
    loadSprite("imagens/F3Temple/blocos templo.png");
    sprite.setTextureRect(IntRect(0, 54, 101, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoTemplo3::update()
{

}
void TerrenoTemplo3::animacao()
{

}





