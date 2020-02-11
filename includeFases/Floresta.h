/*
    Fase 1
*/
#pragma once
#include "../includeFases/Fase.h"
namespace Fases
{
    class Floresta : public Fase
    {
    private:

    public:
        Floresta(Mecanismo* mec);
        ~Floresta();

        void criaInimigos();
        void criaTerreno();
        void criaObstaculos();

        void criaFundo();
    };
}

