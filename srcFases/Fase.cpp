#include "../includeFases/Fase.h"
using namespace Fases;

const float Fase::tamTerreno(50);
Fase::Fase(Mecanismo* mec) : mec(mec)
{

}
Fase::~Fase()
{

}
void Fase::adicionaTerreno(Terreno* t)
{
    mec->addListaTerreno(t);
}
void Fase::adicionaIniNaoAtacavel(Inimigo* i)
{
    mec->addListaInimigosNaoAtacaveis(i);

}
void Fase::adicionaIniAtacavel(Inimigo* i)
{
    mec->addListaInimigosAtacaveis(i);
}
void Fase::adicionaObstaculo(Obstaculo* o)
{
    mec->addListaObstaculos(o);
}
void Fase::adicionaBackGround(Background* b)
{
    mec->addListaBackGrounds(b);
}
void Fase::adicionaForeGround(Background* f)
{
    mec->addListaForeGrounds(f);
}
