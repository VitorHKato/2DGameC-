#include "../includeInimigos/Sapo.h"
using namespace Inimigos;

Sapo::Sapo(int x, int y, JogadorUm* playerOne, JogadorDois* playerTwo) : Inimigo(x, y), playerOne(playerOne),
playerTwo(playerTwo)
{
    contJump = 0;
    inicializa();
    setTamanho(Vector2f(22, 18));
    setPosicao(Vector2f(x, y));
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Yellow);
}
Sapo::~Sapo()
{

}
void Sapo::inicializa()
{
    loadSprite("imagens/enemies/Sapo.png");
    sprite.setTextureRect(IntRect(0, 1, 13, 12));              ///Intervalo (quadrado) que o sapo ocupa da imagem
    sprite.setPosition(getPosicao());
    sprite.setScale(2, 2);
}
void Sapo::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 15)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1 );
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getJump() && getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()*13, 12, 13, 12));
    else if(getJump() && !getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()*13 + 13, 12, -13, 12));
    else if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(getFrameAnimacao()*13, 1, 13, 12));     ///Multiplica pela coordenada do ponto a esquerda da imagem
    else
        sprite.setTextureRect(IntRect(getFrameAnimacao()*13 + 13, 1, -13, 12));
}
void Sapo::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    float dXOne = playerOne->getPosicao().x - pos.x;             ///Guarda distância entre o sapo e os jogadores
    float dXTwo = playerTwo->getPosicao().x - pos.x;
    float dYOne = playerOne->getPosicao().y - pos.y;
    float dYTwo = playerTwo->getPosicao().y - pos.y;

    if(((dXOne < 250) && (dXOne > -250) && (dYOne < 30) && (dYOne > -30)) ||
       ((dXTwo < 250) && (dXTwo > -250) && (dYTwo < 30) && (dYTwo > -30)))  ///Se os jogadores estiverem perto                 ///Se o jogador estiver neste intervalo de distancia
    {
        contJump++;                                                     ///Começa um contador para o sapo pular
        if(contJump == 100)
        {
            setJump(true);
            ///Atualiza velocidade com base na aceleração e na gravidade
            setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x,
                                   getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE - 20));
            contJump = 0;
        }
    }

    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    if(getOlhandoDireita())
        setPosicao(Vector2f(pos.x + 0.7, pos.y));
    else
        setPosicao(Vector2f(pos.x - 0.7, pos.y));


    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    if(!morreu)
        animacao();
    else
        setPosicao(Vector2f(-100, -100));
}



