#include "../includeObstaculos/Aranha.h"
using namespace Obstaculos;

Aranha::Aranha(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Obstaculo(x, y),
playerOne(playerOne), playerTwo(playerTwo)
{
    contador = 0;
    inicializa();
    setTamanho(Vector2f(24, 22));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Magenta);
}
Aranha::~Aranha()
{

}
void Aranha::inicializa()
{
    loadSprite("imagens/obstacles/Aranha.png");
    sprite.setTextureRect(IntRect(4, 226, 12, 11));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Aranha::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 20)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(4 + getFrameAnimacao()*12, 226, 13, 11));
    else
        sprite.setTextureRect(IntRect(4 + getFrameAnimacao()*12 +13, 226, -13, 11));
}
void Aranha::update()
{
   Vector2f pos = getPosicao();                                  ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x - pos.x;             ///Guarda distância entre a aranha e os jogadores
    float dXTwo = playerTwo->getPosicao().x - pos.x;
    float dYOne = playerOne->getPosicao().y - pos.y;
    float dYTwo = playerTwo->getPosicao().y - pos.y;

    contador++;
    if(getOlhandoDireita() && contador <= 15)
    {
        setPosicao(Vector2f(pos.x + 1.0, pos.y));
        if(contador == 15)
            setOlhandoDireita(false);
    }
    else if(!getOlhandoDireita() && contador <= 30)
    {
        setPosicao(Vector2f(pos.x - 1.0, pos.y));
        if(contador >= 30)
            setOlhandoDireita(true);
        contador = 0;
    }

    ///Atualiza posições
    if((dXOne < 250) && (dXOne > -250) && (dYOne < 10) ||
       (dXTwo < 250) && (dXTwo > -250) && (dYTwo < 10))                 ///Se os jogadores estiverem perto
        setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    animacao();

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());
}

