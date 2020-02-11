#include "../includeJogadores/JogadorUm.h"
using namespace Jogadores;

JogadorUm::JogadorUm(int x, int y) : Jogador(x, y)
{
    inicializa();
    ///Cria atributos do shape de colisão
    shape.setSize(getTamanho());
    shape.setPosition(getPosicao());
    shape.setFillColor(Color::Black);

}
JogadorUm::~JogadorUm()
{

}
void JogadorUm::inicializa()
{
    loadSprite("imagens/Heroi/Players.png");
    ///Tamanho do shape está diretamente relacionado com o tamanho da sprite*escala
    sprite.setTextureRect(IntRect(0, 0, 18, 30));              ///Recorte da imagem
    sprite.setPosition(getPosicao());
    sprite.setScale(1.5, 1.5);                                  ///Tamanho da imagem
}
void JogadorUm::animacao()
{
    setFrame(getFrame()+1);                                                             ///Incrementa frame

    if(getFrame() == 10)                                         ///Quando der 15 frames, incrementa o frame de animacao
    {
        setFrameAnimacao(getFrameAnimacao() + 1);
        setFrame(0);
        if(getFrameAnimacao() == 4)                               ///Quando chegar em 4 frames de animação, zera
            setFrameAnimacao(0);
    }

    if(getParado() && getOlhandoDireita())                          ///parado e olhando para direita
        sprite.setTextureRect(IntRect(0, 0, 18, 30));
    else if(getParado() && !getOlhandoDireita())
        sprite.setTextureRect(IntRect(18, 0, -18, 30));             ///parado e olhando para esquerda
    else if(getOlhandoDireita())
        sprite.setTextureRect(IntRect(18 * getFrameAnimacao(), 0, 18, 30));     ///andando e olhando para direita
    else
        sprite.setTextureRect(IntRect(18 * getFrameAnimacao() + 18, 0, -18, 30));   ///andando e olhando para esquerda
}

