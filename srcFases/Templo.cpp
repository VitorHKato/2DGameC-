#include "../includeFases/Templo.h"
using namespace Fases;
Templo::Templo(Mecanismo* mec) : Fase(mec)
{
    criaInimigos();
    criaObstaculos();
    criaTerreno();
    criaFundo();
}
Templo::~Templo()
{

}
void Templo::criaInimigos()
{
    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    float y = Gerenciador_Grafico::getHEIGHT()*2;
    float x = Gerenciador_Grafico::getWIDTH()*2;

    ///1 - Cria MechaBomba
    ///2 - Cria Morcego
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    ///5 - Cria TorradaZombie
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i + y);
                adicionaIniNaoAtacavel(a);
            }
            else if(m[i][j] == 2)
            {
                Morcego *a = new Morcego(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
            else if(m[i][j] == 5)
            {
                TorradaZombie *a = new TorradaZombie(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniNaoAtacavel(a);
            }
        }
    }

    ///tela 2
    int m2[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 4, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH();

    ///1 - Cria MechaBomba
    ///2 - Cria Morcego
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    ///5 - Cria TorradaZombie
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i + y);
                adicionaIniNaoAtacavel(a);
            }
            else if(m2[i][j] == 2)
            {
                Morcego *a = new Morcego(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m2[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m2[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
            else if(m2[i][j] == 5)
            {
                TorradaZombie *a = new TorradaZombie(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniNaoAtacavel(a);
            }
        }
    }

    ///tela 3
    int m3[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = 0;

    ///1 - Cria MechaBomba
    ///2 - Cria Morcego
    ///3 - Cria Bomba, true (olhandoDireita)
    ///4 - Cria Bomba, false (olhandoEsquerda)
    ///5 - Cria TorradaZombie
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i + y);
                adicionaIniNaoAtacavel(a);
            }
            else if(m3[i][j] == 2)
            {
                Morcego *a = new Morcego(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniAtacavel(a);
            }
            else if(m3[i][j] == 3)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), true);
                adicionaIniNaoAtacavel(a);
            }
            else if(m3[i][j] == 4)
            {
                Bomba *a = new Bomba(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois(), false);
                adicionaIniNaoAtacavel(a);
            }
            else if(m3[i][j] == 5)
            {
                TorradaZombie *a = new TorradaZombie(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaIniNaoAtacavel(a);
            }
        }
    }

    x = 0;
    y = Gerenciador_Grafico::getHEIGHT()*3;

    ///Cria chefao na ultima tela
    Minotauro *boss = new Minotauro(x + 500, y + 400, mec->getJogadorUm(), mec->getJogadorDois());
    adicionaIniAtacavel(boss);

}
void Templo::criaTerreno()
{
    int m[12][22] = {   {4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},     ///0
                        {4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///2
                        {4, 4, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3},     ///3
                        {4, 4, 0, 0, 0, 0, 0, 0, 3, 6, 0, 0, 6, 0, 2, 0, 2, 0, 2, 0, 0, 3},     ///4
                        {4, 4, 4, 0, 4, 0, 0, 3, 3, 3 ,0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3},     ///5
                        {8, 8, 0, 0, 0, 0, 4, 3, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 6, 3},     ///6
                        {4, 8, 0, 0, 4, 4, 4, 3, 6, 0, 4, 0, 6, 0, 3, 4, 0, 6, 4, 6, 6, 8},     ///7
                        {4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3},     ///8
                        {4, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 2, 0, 2, 0, 0, 0, 0, 3},     ///9
                        {4, 7, 2, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 2, 0, 0, 0},     ///10
                        {2, 7, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0},     ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    float y = Gerenciador_Grafico::getHEIGHT()*2;
    float x = Gerenciador_Grafico::getWIDTH()*2;

    ///1 - Cria bloco marrom, true (100x50)
    ///2 - Cria bloco marrom, false (100x50)
    ///3 - Cria bloco preto desenho circular, true (50x50)
    ///4 - Cria bloco preto desenho circular, false (50x50)
    ///5 - Cria bloco preto desenho circular, true (100x50)
    ///6 - Cria bloco preto desenho circular, false (100x50)
    ///7 - Cria bloco crânio, true (50x50)
    ///8 - Cria bloco crânio, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 2)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 3)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 4)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 5)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 6)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 7)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 8)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

    ///tela 2

    int m2[12][22] = {  {4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},     ///0
                        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///1
                        {4, 0, 0, 6, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 6, 0, 6, 0, 3},     ///3
                        {4, 0, 0, 0, 0, 0, 0, 8, 0, 0, 6, 0, 6, 0, 8, 6, 0, 3, 0, 0, 0, 3},     ///4
                        {4, 0, 0, 8, 0, 0, 0, 0, 0, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///5
                        {8, 0, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///6
                        {4, 8, 8, 8, 0, 0, 6, 0, 6, 0, 8, 0, 0, 6, 0, 0, 0, 0, 0, 0, 8, 8},     ///7
                        {0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///8
                        {4, 3, 0, 0, 7, 2, 0, 2, 0, 2, 0, 2, 4, 0, 0, 1, 0, 0, 0, 0, 0, 3},     ///9
                        {4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 0, 0, 0, 3},     ///10
                        {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0},     ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH();

    ///1 - Cria bloco marrom, true (100x50)
    ///2 - Cria bloco marrom, false (100x50)
    ///3 - Cria bloco preto desenho circular, true (50x50)
    ///4 - Cria bloco preto desenho circular, false (50x50)
    ///5 - Cria bloco preto desenho circular, true (100x50)
    ///6 - Cria bloco preto desenho circular, false (100x50)
    ///7 - Cria bloco crânio, true (50x50)
    ///8 - Cria bloco crânio, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 2)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 3)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 4)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 5)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 6)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 7)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 8)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

    ///tela 3

    int m3[12][22] = {  {4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},     ///0
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///1
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///2
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///3
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},     ///4
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 4, 0, 4, 0, 6, 0, 6, 0, 4, 3},     ///5
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3},     ///6
                        {3, 0, 0, 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},     ///7
                        {3, 0, 0, 0, 4, 7, 0, 0, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {3, 4, 0, 0, 7, 2, 0, 0, 0, 0, 0, 6, 0, 0, 7, 0, 6, 0, 6, 0, 0, 3},     ///9
                        {3, 3, 0, 0, 7, 2, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 3},     ///10
                        {2, 0, 0, 4, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0},     ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = 0;

    ///1 - Cria bloco marrom, true (100x50)
    ///2 - Cria bloco marrom, false (100x50)
    ///3 - Cria bloco preto desenho circular, true (50x50)
    ///4 - Cria bloco preto desenho circular, false (50x50)
    ///5 - Cria bloco preto desenho circular, true (100x50)
    ///6 - Cria bloco preto desenho circular, false (100x50)
    ///7 - Cria bloco crânio, true (50x50)
    ///8 - Cria bloco crânio, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 2)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 3)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 4)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 5)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 6)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 7)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 8)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

    ///tela 4 (Chefao)

    int m4[12][22] = {  {3, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3},     ///0
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///1
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///2
                        {7, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///3
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///4
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///5
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///6
                        {7, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 7},     ///7
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///8
                        {7, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 7},     ///9
                        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},     ///10
                        {3, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3},     ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = 0;
    y = Gerenciador_Grafico::getHEIGHT()*3;

    ///1 - Cria bloco marrom, true (100x50)
    ///2 - Cria bloco marrom, false (100x50)
    ///3 - Cria bloco preto desenho circular, true (50x50)
    ///4 - Cria bloco preto desenho circular, false (50x50)
    ///5 - Cria bloco preto desenho circular, true (100x50)
    ///6 - Cria bloco preto desenho circular, false (100x50)
    ///7 - Cria bloco crânio, true (50x50)
    ///8 - Cria bloco crânio, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m4[i][j] == 1)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 2)
            {
                TerrenoTemplo *a = new TerrenoTemplo(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 3)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 4)
            {
                TerrenoTemplo2 *a = new TerrenoTemplo2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 5)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 6)
            {
                TerrenoTemplo3 *a = new TerrenoTemplo3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 7)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m4[i][j] == 8)
            {
                TerrenoTemplo4 *a = new TerrenoTemplo4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

}
void Templo::criaObstaculos()
{
    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    float y = Gerenciador_Grafico::getHEIGHT()*2;
    float x = Gerenciador_Grafico::getWIDTH()*2;

    ///1 - Cria Tartaruga
    ///2 - Cria Fogo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                Tartaruga *a = new Tartaruga(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
            else if(m[i][j] == 2)
            {
                Fogo *a = new Fogo(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
        }
    }

    ///tela 2

    int m2[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH();

    ///1 - Cria Tartaruga
    ///2 - Cria Fogo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                Tartaruga *a = new Tartaruga(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
            else if(m2[i][j] == 2)
            {
                Fogo *a = new Fogo(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
        }
    }

    ///tela 3

    int m3[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = 0;

    ///1 - Cria Tartaruga
    ///2 - Cria Fogo
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                Tartaruga *a = new Tartaruga(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
            else if(m3[i][j] == 2)
            {
                Fogo *a = new Fogo(tamTerreno*j + x, tamTerreno*i + y);
                adicionaObstaculo(a);
            }
        }
    }
}
void Templo::criaFundo()
{
    ///tela 1
    float y = Gerenciador_Grafico::getHEIGHT()*2;
    float x = Gerenciador_Grafico::getWIDTH()*2;

    /*Background *b = new Background(x, y, "imagens/F3Temple/Background1.png");
    adicionaBackGround(b);*/

    ///tela 2
    x = Gerenciador_Grafico::getWIDTH();

    Background *b2 = new Background(x, y, "imagens/F3Temple/Background1.1.jpg");
    adicionaBackGround(b2);


    ///tela 3
    x = 0;

    /*Background *b3 = new Background(x, y, "imagens/F3Temple/Background1.1.jpg");
    adicionaBackGround(b3);*/

    ///tela 4
    y = Gerenciador_Grafico::getHEIGHT()*3;

    Background *b4 = new Background(x, y, "imagens/F3Temple/Background1.1.jpg");
    adicionaBackGround(b4);
}



