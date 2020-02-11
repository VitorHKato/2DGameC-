#include "../includeInimigos/Morcego.h"
using namespace Inimigos;

Morcego::Morcego(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Inimigo(x, y), playerOne(playerOne),
playerTwo(playerTwo)
{
    distancia = 0;
    contVoo = 0;
    bravo = false;
    inicializa();
    setTamanho(Vector2f(26, 28));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
Morcego::~Morcego()
{

}
void Morcego::inicializa()
{
    loadSprite("imagens/enemies/Morcego.png");
    sprite.setTextureRect(IntRect(0, 16, 14, 10));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Morcego::animacaoBravo()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() >= 5)                                         ///Quando der 5 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16, 2, 13, 14));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(!getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16 + 14, 2, -13, 14));
}
void Morcego::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() >= 12)                                         ///Quando der 12 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16, 13, 13, 14));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(!getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 16 + 14, 13, -13, 14));
}
void Morcego::update()
{
    Vector2f pos = getPosicao();                                 ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x - pos.x;             ///Guarda distância entre o morcego e os jogadores
    float dXTwo = playerTwo->getPosicao().x - pos.x;
    float dYOne = playerOne->getPosicao().y - pos.y;
    float dYTwo = playerTwo->getPosicao().y - pos.y;

    ///Atualiza velocidade com base na aceleração
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    if(((dXOne < 250) && (dXOne > -250) && (dYOne < 35) && (dYOne > -35)) ||
       ((dXTwo < 250) && (dXTwo > -250) && (dYTwo < 35) && (dYTwo > -35)))
    {
        bravo = true;                ///Se os jogadores estiverem perto, o morcego fica bravo
        distancia = 30;             ///A distancia é usada pra determinar o quanto o morcego vai se mover
    }
    else
    {
        bravo = false;
        distancia = 100;
    }


    contVoo++;
    if(contVoo >= distancia && getOlhandoDireita())
    {
        setOlhandoDireita(false);
        contVoo = 0;
    }
    else if(contVoo >= distancia && !getOlhandoDireita())
    {
        setOlhandoDireita(true);
        contVoo = 0;
    }

    if(getOlhandoDireita() && !bravo)
        setPosicao(Vector2f(pos.x + 1.5, pos.y));
    else if(!getOlhandoDireita() && !bravo)
        setPosicao(Vector2f(pos.x - 1.5, pos.y));
    else if(getOlhandoDireita() && bravo)
        setPosicao(Vector2f(pos.x + 4.5, pos.y));
    else if(!getOlhandoDireita() && bravo)
        setPosicao(Vector2f(pos.x - 4.5, pos.y));

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    if(!morreu && bravo)
        animacaoBravo();
    else if(!morreu && !bravo)
        animacao();
    else if (morreu)
    {
        setTamanho(Vector2f(0, 0));
        setPosicao(Vector2f(-100, -100));
    }


}



