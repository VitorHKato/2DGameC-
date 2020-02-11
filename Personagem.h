#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
private:
    ///Atributos de movimenta��o do personagem
    Vector2f velocidade;
    Vector2f aceleracao;
    ///Contadores de frame para a anima��o
    int frame;
    int frameAnimacao;
    ///Identificar e permitir apenas 1 pulo
    bool jump;
    bool isJumping;

    bool olhandoDireita;                                ///Identifica lado que o personagem esta olhando (animacao)
    bool parado;                                        ///Identifica se est� parado (animacao)
    bool colidiu;
    bool bateuParede;

protected:
    static const float GRAVIDADE;                       ///Gravidade constante
    bool morreu;
public:
    Personagem(int x, int y);
    ~Personagem();

    void setVelocidade(Vector2f velocidade);
    Vector2f getVelocidade();
    void setAceleracao(Vector2f aceleracao);
    Vector2f getAceleracao();
    void setFrame(int frame);
    int getFrame();
    void setFrameAnimacao(int frameAnimacao);
    int getFrameAnimacao();
    void setJump(bool jump);
    bool getJump();
    void setIsJumping(bool isJumping);
    bool getIsJumping();
    void setOlhandoDireita(bool olhandoDireita);
    bool getOlhandoDireita();
    void setColidiu(bool colidiu);
    bool getColidiu();
    void setBateuParede(bool bateuParede);
    bool getBateuParede();
    void setParado(bool parado);
    bool getParado();
    virtual void setMorreu(bool morreu);

};

