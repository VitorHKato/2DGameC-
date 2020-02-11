#include "../includeObstaculos/Folha.h"
using namespace Obstaculos;

Folha::Folha(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Obstaculo(x, y),
playerOne(playerOne), playerTwo(playerTwo)
{
    inicializa();
    setTamanho(Vector2f(24, 28));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
Folha::~Folha()
{

}
void Folha::inicializa()
{
    loadSprite("imagens/obstacles/Folha.png");
    sprite.setTextureRect(IntRect(8, 114, 12, 14));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Folha::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(8 + getFrameAnimacao()*32, 18, 13, 14));
    else
        sprite.setTextureRect(IntRect(8 + getFrameAnimacao()*32 + 13, 18, -13, 14));
}
void Folha::update()
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
