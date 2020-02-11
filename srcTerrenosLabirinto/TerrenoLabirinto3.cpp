#include "../includeTerrenosLabirinto/TerrenoLabirinto3.h"
using namespace TerrenosLabirinto;
TerrenoLabirinto3::TerrenoLabirinto3(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoLabirinto3::~TerrenoLabirinto3()
{

}
void TerrenoLabirinto3::inicializa()
{
    loadSprite("imagens/F2Lab/blocos labirinto.png");
    sprite.setTextureRect(IntRect(68, 27, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoLabirinto3::update()
{

}
void TerrenoLabirinto3::animacao()
{

}





