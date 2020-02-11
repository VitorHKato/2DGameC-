/*
    Fase 2
*/
#pragma once
#include "../includeFases/Fase.h"

namespace Fases
{
    class Labirinto : public Fase
    {
    private:

    public:
        Labirinto(Mecanismo* mec);
        ~Labirinto();

        void criaInimigos();
        void criaTerreno();
        void criaObstaculos();

        void criaFundo();
    };
}

