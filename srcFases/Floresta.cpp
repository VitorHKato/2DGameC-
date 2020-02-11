#include "../includeFases/Floresta.h"
using namespace Fases;
Floresta::Floresta(Mecanismo* mec) : Fase(mec)
{
    criaFundo();
    criaObstaculos();
    criaInimigos();
    criaTerreno();
}
Floresta::~Floresta()
{

}
void Floresta::criaInimigos()
{
    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    ///1 - Cria MechaBomba
    ///2 - Cria Sapo
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j, tamTerreno*i);
                adicionaIniNaoAtacavel(a);
            }
            else if(m[i][j] == 2)
            {
                Sapo *a = new Sapo(tamTerreno*j, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
        }
    }

    ///tela2
    int m2[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    float x = Gerenciador_Grafico::getWIDTH();      ///Aux para criar a tela seguinte

    ///1 - Cria MechaBomba
    ///2 - Cria Sapo
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i);
                adicionaIniNaoAtacavel(a);
            }
            else if(m2[i][j] == 2)
            {
                Sapo *a = new Sapo(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m2[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m2[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
        }
    }

    ///tela3
    int m3[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*2;      ///Aux para criar a tela seguinte

    ///1 - Cria MechaBomba
    ///2 - Cria Sapo
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i);
                adicionaIniNaoAtacavel(a);
            }
            else if(m3[i][j] == 2)
            {
                Sapo *a = new Sapo(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m3[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m3[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
        }
    }

}
void Floresta::criaTerreno()
{
    int m[12][22] = {   {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},     ///0
                        {2, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {2, 0, 0, 5, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 3},     ///2
                        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///3
                        {2, 0, 6, 0, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2},     ///4
                        {2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 5, 6, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2},     ///5
                        {2, 5, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 2},     ///6
                        {2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///7
                        {2, 5, 5, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2},     ///8
                        {2, 0, 0, 0, 5, 5, 5, 2, 0, 0, 0, 6, 0, 0, 0, 0, 2, 0, 5, 5, 0, 2},     ///9
                        {2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///10
                        {2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    ///1 - Cria chao com grama, false (100x50)
    ///2 - Cria Tronco, true (50x50)
    ///3 - Cria Tronco, false (50x50)
    ///4 - Cria Pedrinhas, true (50x50)
    ///5 - Cria Pedrinhas, false (50x50)
    ///6 - Cria Tronco Grande, false (300x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                TerrenoFloresta *a = new TerrenoFloresta(tamTerreno*j, tamTerreno*i, false);      ///Coordenadas 100,50,bool
                adicionaTerreno(a);
            }
            else if(m[i][j] == 2)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 3)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 4)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 5)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 6)
            {
                TerrenoFloresta4 *a = new TerrenoFloresta4(tamTerreno*j, tamTerreno*i, false);
                adicionaTerreno(a);
            }
        }
    }

    ///Tela2
    int m2[12][22] = {  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {2, 6, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3},     ///2
                        {2, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 3},     ///3
                        {2, 0, 6, 0, 0, 0, 0, 5, 5, 0, 0, 6, 0, 0, 0, 0, 3, 2, 3, 0, 0, 2},     ///4
                        {2, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///5
                        {2, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 2},     ///6
                        {2, 0, 0, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///7
                        {2, 5, 5, 5, 5, 5, 0, 0, 4, 0, 0, 3, 0, 3, 0, 3, 0, 3, 0, 0, 0, 2},     ///8
                        {2, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///9
                        {2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///10
                        {2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    float x = Gerenciador_Grafico::getWIDTH();      ///Aux para criar a tela seguinte

    ///1 - Cria chao com grama, false (100x50)
    ///2 - Cria Tronco, true (50x50)
    ///3 - Cria Tronco, false (50x50)
    ///4 - Cria Pedrinhas, true (50x50)
    ///5 - Cria Pedrinhas, false (50x50)
    ///6 - Cria Tronco Grande, false (300x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                TerrenoFloresta *a = new TerrenoFloresta(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 2)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j + x, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 3)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 4)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j + x, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 5)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 6)
            {
                TerrenoFloresta4 *a = new TerrenoFloresta4(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
        }
    }

    ///Tela3
    int m3[12][22] = {  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///1
                        {2, 5, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 2},     ///2
                        {2, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 5, 0, 3, 0, 0, 0, 2},     ///3
                        {2, 0, 6, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 4, 0, 2},     ///4
                        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 2},     ///5
                        {2, 0, 0, 0, 0, 0, 0, 2, 3, 6, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 2},     ///6
                        {2, 0, 6, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///7
                        {2, 3, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2},     ///8
                        {2, 0, 0, 0, 5, 5, 5, 2, 0, 0, 3, 0, 3, 0, 3, 0, 5, 5, 5, 5, 5, 3},     ///9
                        {2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///10
                        {2, 0, 5, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*2;      ///Aux para criar a tela seguinte

    ///1 - Cria chao com grama, false (100x50)
    ///2 - Cria Tronco, true (50x50)
    ///3 - Cria Tronco, false (50x50)
    ///4 - Cria Pedrinhas, true (50x50)
    ///5 - Cria Pedrinhas, false (50x50)
    ///6 - Cria Tronco Grande, false (300x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                TerrenoFloresta *a = new TerrenoFloresta(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 2)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j + x, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 3)
            {
                TerrenoFloresta3 *a = new TerrenoFloresta3(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 4)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j + x, tamTerreno*i, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 5)
            {
                TerrenoFloresta2 *a = new TerrenoFloresta2(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 6)
            {
                TerrenoFloresta4 *a = new TerrenoFloresta4(tamTerreno*j + x, tamTerreno*i, false);
                adicionaTerreno(a);
            }
        }
    }
}
void Floresta::criaObstaculos()
{
    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    ///1 - Cria Folha
    ///2 - Cria Cogumelo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                Folha *a = new Folha(tamTerreno*j, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
            else if(m[i][j] == 2)
            {
                Cogumelo *a = new Cogumelo(tamTerreno*j, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }

    ///Tela2
    int m2[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1


    float x = Gerenciador_Grafico::getWIDTH();      ///Aux para criar a tela seguinte

    ///1 - Cria Folha
    ///2 - Cria Cogumelo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                Folha *a = new Folha(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
            else if(m2[i][j] == 2)
            {
                Cogumelo *a = new Cogumelo(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }

    ///Tela3
    int m3[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1


    x = Gerenciador_Grafico::getWIDTH()*2;      ///Aux para criar a tela seguinte

    ///1 - Cria Folha
    ///2 - Cria Cogumelo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                Folha *a = new Folha(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
            else if(m3[i][j] == 2)
            {
                Cogumelo *a = new Cogumelo(tamTerreno*j + x, tamTerreno*i, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }
}
void Floresta::criaFundo()
{
    ///tela1
    ///BackGrounds
    Background *a = new Background(0, 0, "imagens/F1Forest/Background2.png");
    adicionaBackGround(a);

    Background *b = new Background(0, 0, "imagens/F1Forest/Clouds1.png");
    adicionaBackGround(b);

    ///ForeGrounds
    /*Background *f = new Background(900, 50, "imagens/F1Forest/Arvore3.png");
    adicionaForeGround(f);*/

    /*Background *g = new Background(200, 400, "imagens/F1Forest/Arvore1.png");
    adicionaForeGround(g);*/
    ///tela2

    float x = Gerenciador_Grafico::getWIDTH();

    Background *a2 = new Background(x, 0, "imagens/F1Forest/Background3.png");
    adicionaBackGround(a2);

    Background *b2 = new Background(x, 0, "imagens/F1Forest/Clouds1.png");
    adicionaBackGround(b2);


    ///tela 3

    x = Gerenciador_Grafico::getWIDTH()*2;

    Background *a3 = new Background(x, 0, "imagens/F1Forest/Background5.png");
    adicionaBackGround(a3);

    Background *b3 = new Background(x, 0, "imagens/F1Forest/Clouds2.png");
    adicionaBackGround(b3);
}
