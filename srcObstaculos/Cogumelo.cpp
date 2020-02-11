#include "../includeObstaculos/Cogumelo.h"
using namespace Obstaculos;
Cogumelo::Cogumelo(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Obstaculo(x, y), playerOne(playerOne),
playerTwo(playerTwo)
{
    inicializa();
    setTamanho(Vector2f(25, 20));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
Cogumelo::~Cogumelo()
{

}
void Cogumelo::inicializa()
{
    loadSprite("imagens/obstacles/Cogumelo.png");
    sprite.setTextureRect(IntRect(2, 11, 27, 20));
    sprite.setPosition(getPosicao());
    sprite.setScale(1, 1);
}
void Cogumelo::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 10 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 14)                               ///Quando chegar em 14 frames de animação, zera
            setFrameAnimacao(1);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()*32, 11, 27, 20));
    else
        sprite.setTextureRect(IntRect(getFrameAnimacao()*32, 11, -27, 20));
}
void Cogumelo::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x;             ///Guarda a posicao X dos jogadores
    float dXTwo = playerTwo->getPosicao().x;

    if(dXOne < pos.x || dXTwo < pos.x)
        setOlhandoDireita(false);
    else if(dXOne > pos.x || dXTwo > pos.x)
        setOlhandoDireita(true);

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


