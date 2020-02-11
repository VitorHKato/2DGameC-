#include "Entidade.h"
Entidade::Entidade(int x, int y)
{
    setPosicao(Vector2f(x, y));
}
Entidade::~Entidade()
{

}
///Sets e Gets
void Entidade::setWindow(RenderWindow *window)
{
    this->window = window;
}
RenderWindow* Entidade::getWindow()
{
    return window;
}
void Entidade::setShape(RectangleShape shape)
{
    this->shape = shape;
}
RectangleShape Entidade::getShape()
{
    return shape;
}
void Entidade::setTamanho(Vector2f tamanho)
{
    this->tamanho = tamanho;
}
Vector2f Entidade::getTamanho()
{
    return tamanho;
}
void Entidade::setPosicao(Vector2f posicao)
{
    this->posicao = posicao;
}
Vector2f Entidade::getPosicao()
{
    return posicao;
}
void Entidade::setTextura(Texture textura)
{
    this->textura = textura;
}
Texture Entidade::getTextura()
{
    return textura;
}
void Entidade::setSprite(Sprite sprite)
{
    this->sprite = sprite;
}
Sprite Entidade::getSprite()
{
    return sprite;
}
///
void Entidade::imprimir()
{
    //getWindow()->draw(getShape());
    getWindow()->draw(sprite);
    update();
}
void Entidade::loadSprite(const char* arq)
{
    textura.loadFromFile(arq);
    textura.setSmooth(false);
    sprite.setTexture(textura);
}
