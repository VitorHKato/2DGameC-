#include "../includeFundos/Background.h"
using namespace Fundos;
Background::Background(int x, int y, const char* arq) : Entidade(x, y)
{
    loadSprite(arq);                            ///Arquivo com a imagem
    setPosicao(Vector2f(x, y));
    sprite.setPosition(getPosicao());
}
Background::~Background()
{

}
void Background::update()
{

}
void Background::inicializa()
{

}
void Background::animacao()
{

}
