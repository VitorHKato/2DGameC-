#include "../includeObstaculos/Fogo.h"
using namespace Obstaculos;
Fogo::Fogo(int x, int y) : Obstaculo(x, y)
{
    inicializa();
    setTamanho(Vector2f(20, 32));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
Fogo::~Fogo()
{

}
void Fogo::inicializa()
{
    loadSprite("imagens/obstacles/Fogo.png");
    sprite.setTextureRect(IntRect(4, 68, 10, 16));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Fogo::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 10 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1);
        setFrame(0);
        if(getFrameAnimacao() == 19 && getOlhandoDireita())      ///A cada rotacao de imagens(19), troca de lado e zera
        {
            setFrameAnimacao(0);
            setOlhandoDireita(false);
        }
        else if(getFrameAnimacao() == 19 && !getOlhandoDireita())
        {
            setFrameAnimacao(0);
            setOlhandoDireita(true);
        }
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(4 + getFrameAnimacao()*10, 68, 10, 16));
    else
        sprite.setTextureRect(IntRect(4 + getFrameAnimacao()*10 + 10, 68, -10, 16));
}
void Fogo::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    if(getFrameAnimacao() < 2 || getFrameAnimacao() > 15)       ///Se a tocha estiver apagada, ele não da dano
        setTamanho(Vector2f(0, 0));
    else
        setTamanho(Vector2f(20, 32));

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

