#include "../includeTerrenosLabirinto/TerrenoLabirinto2.h"
using namespace TerrenosLabirinto;
TerrenoLabirinto2::TerrenoLabirinto2(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoLabirinto2::~TerrenoLabirinto2()
{

}
void TerrenoLabirinto2::inicializa()
{
    loadSprite("imagens/F2Lab/blocos labirinto.png");
    sprite.setTextureRect(IntRect(120, 27, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoLabirinto2::update()
{

}
void TerrenoLabirinto2::animacao()
{

}




