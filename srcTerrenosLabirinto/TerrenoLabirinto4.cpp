#include "../includeTerrenosLabirinto/TerrenoLabirinto4.h"
using namespace TerrenosLabirinto;
TerrenoLabirinto4::TerrenoLabirinto4(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoLabirinto4::~TerrenoLabirinto4()
{

}
void TerrenoLabirinto4::inicializa()
{
    loadSprite("imagens/F2Lab/blocos labirinto.png");
    sprite.setTextureRect(IntRect(16, 27, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoLabirinto4::update()
{

}
void TerrenoLabirinto4::animacao()
{

}






