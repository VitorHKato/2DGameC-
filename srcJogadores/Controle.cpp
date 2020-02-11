#include "../includeJogadores/Controle.h"
using namespace Jogadores;

Controle::Controle()
{

}
Controle::~Controle()
{

}
///Sets
void Controle::setJogadorUm(JogadorUm* playerOne)
{
    this->playerOne = playerOne;
}
void Controle::setJogadorDois(JogadorDois* playerTwo)
{
    this->playerTwo = playerTwo;
}
///
void Controle::movimentacao()
{
    ///playerTwo
    ///movimentacao
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        playerTwo->setVelocidade(Vector2f(-4, playerTwo->getVelocidade().y));
        playerTwo->setOlhandoDireita(false);
        playerTwo->setParado(false);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        playerTwo->setVelocidade(Vector2f(4, playerTwo->getVelocidade().y));
        playerTwo->setOlhandoDireita(true);
        playerTwo->setParado(false);
    }
    else
        {
            playerTwo->setVelocidade(Vector2f(0, playerTwo->getVelocidade().y));
            playerTwo->setParado(true);
        }
    ///pulo
    if(playerTwo->getJump() && !playerTwo->getIsJumping())          ///Se ele pulou e está no ar, atualiza gravidade
    {
        playerTwo->setVelocidade(Vector2f(playerTwo->getVelocidade().x, -23));
        playerTwo->setJump(false);
        playerTwo->setParado(false);
    }
    else
        playerTwo->setAceleracao(Vector2f(playerTwo->getAceleracao().x, 0));

    ///playerOne
    ///movimentacao
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        playerOne->setVelocidade(Vector2f(-4, playerOne->getVelocidade().y));
        playerOne->setOlhandoDireita(false);
        playerOne->setParado(false);
    }
    else if(Keyboard::isKeyPressed(Keyboard::D))
    {
        playerOne->setVelocidade(Vector2f(4, playerOne->getVelocidade().y));
        playerOne->setOlhandoDireita(true);
        playerOne->setParado(false);
    }
    else
        {
            playerOne->setVelocidade(Vector2f(0, playerOne->getVelocidade().y));
            playerOne->setParado(true);
        }
    ///pulo
    if(playerOne->getJump() && !playerOne->getIsJumping())
    {
        playerOne->setVelocidade(Vector2f(playerOne->getVelocidade().x, -23));
        playerOne->setJump(false);
        playerOne->setParado(false);
    }
    else
        playerOne->setAceleracao(Vector2f(playerOne->getAceleracao().x, 0));
}
void Controle::comandos(Event event)
{

    ///Identifica e atualiza se pulou e se está no ar, playerOne
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::W)
    {
        playerOne->setJump(true);   ///Pulou
        playerOne->setIsJumping(true);  ///Está no ar
    }

    if(event.type == Event::KeyReleased && event.key.code == Keyboard::W)
    {
        playerOne->setJump(false);
    }

    ///playerTwo
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
    {
        playerTwo->setJump(true);
        playerTwo->setIsJumping(true);
    }

    if(event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
    {
        playerTwo->setJump(false);
    }
}
