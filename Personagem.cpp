#include "Personagem.h"
const float Personagem::GRAVIDADE = 2;

Personagem::Personagem(int x, int y) : Entidade(x, y)               ///Posição herdada de entidade
{
    morreu = false;
    setFrame(0);
    setFrameAnimacao(0);
}
Personagem::~Personagem()
{

}
///Sets e Gets
void Personagem::setMorreu(bool morreu)
{
    this->morreu = morreu;
}

void Personagem::setColidiu(bool colidiu)
{
    this->colidiu = colidiu;
}
bool Personagem::getColidiu()
{
    return colidiu;
}
void Personagem::setVelocidade(Vector2f velocidade)
{
    this->velocidade = velocidade;
}
Vector2f Personagem::getVelocidade()
{
    return velocidade;
}
void Personagem::setAceleracao(Vector2f aceleracao)
{
    this->aceleracao = aceleracao;
}
Vector2f Personagem::getAceleracao()
{
    return aceleracao;
}
void Personagem::setFrame(int frame)
{
    this->frame = frame;
}
int Personagem::getFrame()
{
    return frame;
}
void Personagem::setFrameAnimacao(int frameAnimacao)
{
    this->frameAnimacao = frameAnimacao ;
}
int Personagem::getFrameAnimacao()
{
    return frameAnimacao;
}
void Personagem::setJump(bool jump)
{
    this->jump = jump;
}
bool Personagem::getJump()
{
    return jump;
}
void Personagem::setIsJumping(bool isJumping)
{
    this->isJumping = isJumping;
}
bool Personagem::getIsJumping()
{
    return isJumping;
}
void Personagem::setOlhandoDireita(bool olhandoDireita)
{
    this->olhandoDireita = olhandoDireita;
}
bool Personagem::getOlhandoDireita()
{
    return olhandoDireita;
}
void Personagem::setBateuParede(bool bateuParede)
{
    this->bateuParede = bateuParede;
}
bool Personagem::getBateuParede()
{
    return bateuParede;
}
void Personagem::setParado(bool parado)
{
    this->parado = parado;
}
bool Personagem::getParado()
{
    return parado;
}
