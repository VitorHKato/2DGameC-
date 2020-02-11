#include "../includeInimigos/TorradaZombie.h"
using namespace Inimigos;

TorradaZombie::TorradaZombie(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Inimigo(x, y),
playerOne(playerOne), playerTwo(playerTwo)
{
    setOlhandoDireita(true);
    contadorCorrer = 0;
    inicializa();
    setTamanho(Vector2f(31, 29));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
TorradaZombie::~TorradaZombie()
{

}
void TorradaZombie::inicializa()
{
    loadSprite("imagens/enemies/TorradaZombie.png");
    sprite.setTextureRect(IntRect(13, 35, 31, 29));
    sprite.setPosition(getPosicao());
}
void TorradaZombie::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 10 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1);
        setFrame(0);
        if(contadorCorrer < 50)                                       //
        {
            if(getFrameAnimacao() == 6)                               ///Quando chegar em 6 frames de animação, zera
                setFrameAnimacao(0);
        }
        else
        {
            if(contadorCorrer == 50)
                setFrameAnimacao(14);
            if(getFrameAnimacao() >= 18)
                setFrameAnimacao(0);
        }
    }

    if(!getOlhandoDireita())
        sprite.setTextureRect(IntRect(13 + getFrameAnimacao()* 64, 35, 31, 29));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(31 + getFrameAnimacao()* 64 + 14, 35, -31, 29));
}
void TorradaZombie::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    contadorCorrer++;

    ///Atualiza velocidade com base na aceleração e na gravidade
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    if(contadorCorrer < 50)
    {
        if(getOlhandoDireita())
            setPosicao(Vector2f(pos.x + 1.3, pos.y));
        else
            setPosicao(Vector2f(pos.x - 1.3, pos.y));
    }
    else
    {
        if(getOlhandoDireita())
            setPosicao(Vector2f(pos.x + 4.3, pos.y));
        else
            setPosicao(Vector2f(pos.x - 4.3, pos.y));
    }
    if(contadorCorrer == 100)
        contadorCorrer = 0;

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    animacao();

}



