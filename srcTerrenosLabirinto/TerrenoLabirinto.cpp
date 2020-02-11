#include "../includeTerrenosLabirinto/TerrenoLabirinto.h"
using namespace TerrenosLabirinto;
TerrenoLabirinto::TerrenoLabirinto(int x, int y, bool wall) : Terreno(x, y, wall)
{
    setWall(wall);
    inicializa();
    setTamanho(Vector2f(50, 50));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
TerrenoLabirinto::~TerrenoLabirinto()
{

}
void TerrenoLabirinto::inicializa()
{
    loadSprite("imagens/F2Lab/blocos labirinto.png");
    sprite.setTextureRect(IntRect(172, 27, 51, 51));
    sprite.setPosition(getPosicao());
}
void TerrenoLabirinto::update()
{

}
void TerrenoLabirinto::animacao()
{

}




