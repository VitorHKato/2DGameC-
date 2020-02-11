#include "../includeInimigos/Bomba.h"
using namespace Inimigos;

Bomba::Bomba(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo, bool olhandoDireita) : Inimigo(x, y), playerOne(playerOne),
playerTwo(playerTwo)
{
    setOlhandoDireita(olhandoDireita);
    acordou = false;
    inicializa();
    setTamanho(Vector2f(32, 32));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
Bomba::~Bomba()
{

}
void Bomba::inicializa()
{
    loadSprite("imagens/enemies/Bomba.png");
    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(0, 0, 16, 16));
    else
        sprite.setTextureRect(IntRect(16, 0, -16, 16));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Bomba::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 5)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    else if(getOlhandoDireita() && acordou)
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16, 0, 16, 16));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(!getOlhandoDireita() && acordou)
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16 + 16, 0, -16, 16));
}
void Bomba::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x - pos.x;             ///Guarda distância entre o sapo e os jogadores
    float dXTwo = playerTwo->getPosicao().x - pos.x;
    float dYOne = playerOne->getPosicao().y - pos.y;
    float dYTwo = playerTwo->getPosicao().y - pos.y;

    ///Atualiza velocidade com base na aceleração e na gravidade
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    if(((dXOne < 250) && (dXOne > -250) && (dYOne < 30) && (dYOne > -30)) ||
       ((dXTwo < 250) && (dXTwo > -250) && (dYTwo < 30) && (dYTwo > -30))) ///Se os jogadores estiverem perto, ela acorda
       acordou = true;
    else
        setPosicao(Vector2f(pos.x , pos.y));

    if(getOlhandoDireita() && acordou)
        setPosicao(Vector2f(pos.x + 4.5, pos.y));
    else if(!getOlhandoDireita() && acordou)
        setPosicao(Vector2f(pos.x - 4.5, pos.y));

    animacao();

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

}



