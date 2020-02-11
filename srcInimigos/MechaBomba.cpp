#include "../includeInimigos/MechaBomba.h"
using namespace Inimigos;

MechaBomba::MechaBomba(int x, int y) : Inimigo(x, y)
{
    setOlhandoDireita(true);
    inicializa();
    setTamanho(Vector2f(32, 32));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
MechaBomba::~MechaBomba()
{

}
void MechaBomba::setMorreu()
{

}
void MechaBomba::inicializa()
{
    loadSprite("imagens/enemies/MechaBomba.png");
    sprite.setTextureRect(IntRect(0, 0, 16, 16));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void MechaBomba::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 15)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16, 0, 16, 16));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16 + 16, 0, -16, 16));
}
void MechaBomba::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    ///Atualiza velocidade com base na aceleração e na gravidade
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    if(getOlhandoDireita())
        setPosicao(Vector2f(pos.x + 0.5, pos.y));
    else
        setPosicao(Vector2f(pos.x - 0.5, pos.y));

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    animacao();
}

