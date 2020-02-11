#include "../includeJogadores/Jogador.h"
using namespace Jogadores;

Jogador::Jogador(int x, int y) : Personagem(x, y)
{
    ///Inicializa atributos booleanos
    setOlhandoDireita(true);
    setIsJumping(false);
    setJump(false);
    setTamanho(Vector2f(27, 45));
}
Jogador::~Jogador()
{

}
void Jogador::update()
{
    Vector2f pos = getPosicao();                                ///Guarda a posição atual

    ///Atualiza velocidade com base na aceleração e na gravidade
    setVelocidade(Vector2f(getVelocidade().x + getAceleracao().x, getVelocidade().y + getAceleracao().y + Personagem::GRAVIDADE));

    ///Incrementa a posição com base na velocidade
    pos.x += getVelocidade().x;
    pos.y += getVelocidade().y;

    ///Atualiza posições
    setPosicao(Vector2f(pos.x, pos.y));
    shape.setPosition(getPosicao());
    sprite.setPosition(getPosicao());

    if(morreu)
    {
        setPosicao(Vector2f(100, 500));
        setMorreu(false);
    }

    animacao();

}
