#include "../includeObstaculos/Tartaruga.h"
using namespace Obstaculos;
Tartaruga::Tartaruga(int x, int y) : Obstaculo(x, y)
{
    inicializa();
    setTamanho(Vector2f(35, 21));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
Tartaruga::~Tartaruga()
{

}
void Tartaruga::inicializa()
{
    loadSprite("imagens/obstacles/Tartaruga.png");
    sprite.setTextureRect(IntRect(1, 0, 44, 25));
    sprite.setPosition(getPosicao());
    sprite.setScale(0.8, 0.8);
}
void Tartaruga::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 10 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1);
        setFrame(0);
        if(getFrameAnimacao() == 13 && getOlhandoDireita())      ///A cada rotacao de imagens(19), troca de lado e zera
        {
            setFrameAnimacao(0);
            setOlhandoDireita(false);
        }
        else if(getFrameAnimacao() == 13 && !getOlhandoDireita())
        {
            setFrameAnimacao(0);
            setOlhandoDireita(true);
        }
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(1 + getFrameAnimacao()*44, 0, 44, 25));
    else
        sprite.setTextureRect(IntRect(1 + getFrameAnimacao()*44 + 44, 0, -44, 25));
}
void Tartaruga::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    ///Atualiza velocidade com base na aceleração e na gravidade
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    setPosicao(Vector2f(pos.x, pos.y));

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    animacao();
}


