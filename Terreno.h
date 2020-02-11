#pragma once
#include "Entidade.h"

class Terreno : public Entidade
{
private:
    bool wall;                  ///Identifica se � parede ou n�o pela construtora (usado na colisao dos inimigos)
public:
    Terreno(int x, int y, bool wall);
    ~Terreno();

    virtual void inicializa() = 0;
    virtual void update() = 0;

    virtual void setWall(bool wall);
    virtual bool getWall();
};
