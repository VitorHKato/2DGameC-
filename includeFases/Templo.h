/*
    Fase 3
*/
#pragma once
#include "Fase.h"

namespace Fases
{
    class Templo : public Fase
    {
    private:

    public:
        Templo(Mecanismo* mec);
        ~Templo();

        void criaInimigos();
        void criaTerreno();
        void criaObstaculos();

        void criaFundo();
    };
}


