#include "../includeInimigos/Minotauro.h"
using namespace Inimigos;

Minotauro::Minotauro(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Inimigo(x, y), playerOne(playerOne),
playerTwo(playerTwo)
{
    bravo = false;
    vidas = 15;
    inicializa();
    setTamanho(Vector2f(122, 92));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
Minotauro::~Minotauro()
{

}
void Minotauro::inicializa()
{
    loadSprite("imagens/Minotaur(Boss1)/Minotauro.png");
    sprite.setTextureRect(IntRect(3, 15, 53, 42));
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Minotauro::animacaoBravo()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() >= 10)                                         ///Quando der 5 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1);
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 57 + 3, 79, 57, 46));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(!getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 57 + 3 + 57, 79, -57, 46));
}
void Minotauro::animacao()
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
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 52 + 3, 15, 52, 42));    ///Multiplica pela coordenada do ponto a esquerda da imagem
    else if(!getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()* 52 + 3 + 53, 15, -52, 42));
}
void Minotauro::update()
{
    Vector2f pos = getPosicao();                                 ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x - pos.x;             ///Guarda distância entre o morcego e os jogadores
    float dXTwo = playerTwo->getPosicao().x - pos.x;
    float dYOne = playerOne->getPosicao().y - pos.y;
    float dYTwo = playerTwo->getPosicao().y - pos.y;

    ///Atualiza velocidade com base na aceleração
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Se os jogadores estiverem na linha de visão do minotauro
    if(((dYOne < 70) && (dYOne > -70)
        && (!getOlhandoDireita() && playerOne->getPosicao().x < pos.x) || (getOlhandoDireita() && playerOne->getPosicao().x > pos.x))
        || ((dYTwo < 70) && (dYTwo > -70)
        && (!getOlhandoDireita() && playerTwo->getPosicao().x < pos.x) || (getOlhandoDireita() && playerTwo->getPosicao().x > pos.x)))
    {
        bravo = true;         ///Se o minotauro estiver vendo algum dos jogadores, tenta mata-los mais rapidamente
    }
    else
    {
        bravo = false;
    }

    if(getOlhandoDireita() && !bravo)
        setPosicao(Vector2f(pos.x + 5, pos.y));
    else if(!getOlhandoDireita() && !bravo)
        setPosicao(Vector2f(pos.x - 5, pos.y));
    else if(getOlhandoDireita() && bravo)
        setPosicao(Vector2f(pos.x + 8, pos.y));
    else if(!getOlhandoDireita() && bravo)
        setPosicao(Vector2f(pos.x - 8, pos.y));

    if(morreu)
    {
        vidas--;
        setMorreu(false);
    }

    std::cout << vidas << std::endl;

    if(vidas == 0)
        setPosicao(Vector2f(-100, -100));
    else if(!bravo)
        animacao();
    else
        animacaoBravo();

    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

}



