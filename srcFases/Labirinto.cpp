#include "../includeFases/Labirinto.h"
using namespace Fases;
Labirinto::Labirinto(Mecanismo* mec) : Fase(mec)
{
    criaObstaculos();
    criaInimigos();
    criaTerreno();
    criaFundo();
}
Labirinto::~Labirinto()
{

}
void Labirinto::criaInimigos()
{
    float x = Gerenciador_Grafico::getWIDTH()*2;
    float y = Gerenciador_Grafico::getHEIGHT();

    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

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
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i+ y);
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
                        {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*3;

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
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i+ y);
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
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    y = Gerenciador_Grafico::getHEIGHT()*2;

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
                MechaBomba *a = new MechaBomba(tamTerreno*j + x, tamTerreno*i+ y);
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
}
void Labirinto::criaTerreno()
{
    float x = Gerenciador_Grafico::getWIDTH()*2;
    float y = Gerenciador_Grafico::getHEIGHT();

    int m[12][22] = {   {3, 0, 8, 8, 8, 2, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 6},     ///0
                        {3, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///1
                        {2, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 2},     ///2
                        {7, 3, 3, 0, 0, 0, 3, 0, 5, 0, 0, 6, 2, 2, 2, 2, 2, 2, 6, 0, 0, 2},     ///3
                        {3, 0, 4, 4, 4, 4, 4, 0, 5, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},     ///4
                        {2, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2},     ///5
                        {3, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 2},     ///6
                        {7, 8, 8, 0, 5, 0, 0, 0, 5, 0, 0, 2, 2, 4, 4, 2, 4, 0, 0, 0, 0, 2},     ///7
                        {3, 0, 0, 0, 2, 2, 4, 2, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},     ///8
                        {3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///9
                        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0},     ///10
                        {2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 1, 6, 2, 2, 2, 2, 2, 6, 1, 2, 2}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    ///1 - Cria bloco com um quadradinho, true (50x50)
    ///2 - Cria bloco com um quadradinho, false (50x50)
    ///3 - Cria bloco com quatro quadradinhos, true (50x50)
    ///4 - Cria bloco com quatro quadradinhos, false (50x50)
    ///5 - Cria bloco com um rosto, true (50x50)
    ///6 - Cria bloco com um rosto, false (50x50)
    ///7 - Cria bloco de madeira, true (50x50)
    ///8 - Cria bloco de madeira, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m[i][j] == 1)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 2)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 3)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 4)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 5)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 6)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 7)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m[i][j] == 8)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

    ///tela2

    int m2[12][22] = {  {1, 2, 2, 2, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 6, 8, 8, 6, 8, 4, 8, 6},     ///0
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1},     ///1
                        {1, 0, 0, 6, 4, 6, 0, 0, 0, 0, 0, 0, 4, 4, 4, 5, 4, 4, 0, 0, 2, 1},     ///2
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7},     ///3
                        {1, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 4, 2, 0, 1},     ///4
                        {1, 0, 0, 0, 3, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 0, 7},     ///5
                        {1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 1, 0, 7},     ///6
                        {1, 0, 2, 2, 3, 0, 2, 2, 0, 2, 2, 0, 4, 0, 0, 5, 0, 0, 0, 1, 0, 7},     ///7
                        {1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 6, 6, 0, 1},     ///8
                        {1, 2, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 3, 0, 7},     ///9
                        {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 7},     ///10
                        {2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 3, 0, 7}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*3;
    y = Gerenciador_Grafico::getHEIGHT();

    ///1 - Cria bloco com um quadradinho, true (50x50)
    ///2 - Cria bloco com um quadradinho, false (50x50)
    ///3 - Cria bloco com quatro quadradinhos, true (50x50)
    ///4 - Cria bloco com quatro quadradinhos, false (50x50)
    ///5 - Cria bloco com um rosto, true (50x50)
    ///6 - Cria bloco com um rosto, false (50x50)
    ///7 - Cria bloco de madeira, true (50x50)
    ///8 - Cria bloco de madeira, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m2[i][j] == 1)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 2)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 3)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 4)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 5)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 6)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 7)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m2[i][j] == 8)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

    ///tela3

    int m3[12][22] = {  {5, 2, 4, 4, 2, 2, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 6, 4, 6, 4, 0, 6},     ///0
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///1
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},     ///2
                        {5, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 2},     ///3
                        {5, 0, 6, 2, 2, 6, 4, 2, 0, 4, 1, 0, 4, 0, 2, 2, 2, 2, 6, 2, 0, 6},     ///4
                        {5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},     ///5
                        {5, 0, 0, 0, 0, 0, 1, 0, 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2},     ///6
                        {5, 4, 2, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 2},     ///7
                        {5, 0, 0, 0, 0, 0, 1, 7, 0, 0, 5, 4, 2, 4, 2, 2, 4, 2, 2, 0, 0, 4},     ///8
                        {5, 0, 0, 0, 6, 0, 0, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2},     ///9
                        {0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},     ///10
                        {5, 2, 2, 2, 2, 2, 6, 4, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*3;
    y = Gerenciador_Grafico::getHEIGHT()*2;

    ///1 - Cria bloco com um quadradinho, true (50x50)
    ///2 - Cria bloco com um quadradinho, false (50x50)
    ///3 - Cria bloco com quatro quadradinhos, true (50x50)
    ///4 - Cria bloco com quatro quadradinhos, false (50x50)
    ///5 - Cria bloco com um rosto, true (50x50)
    ///6 - Cria bloco com um rosto, false (50x50)
    ///7 - Cria bloco de madeira, true (50x50)
    ///8 - Cria bloco de madeira, false (50x50)
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            if(m3[i][j] == 1)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 2)
            {
                TerrenoLabirinto *a = new TerrenoLabirinto(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 3)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 4)
            {
                TerrenoLabirinto2 *a = new TerrenoLabirinto2(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 5)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 6)
            {
                TerrenoLabirinto3 *a = new TerrenoLabirinto3(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 7)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, true);
                adicionaTerreno(a);
            }
            else if(m3[i][j] == 8)
            {
                TerrenoLabirinto4 *a = new TerrenoLabirinto4(tamTerreno*j + x, tamTerreno*i + y, false);
                adicionaTerreno(a);
            }
        }
    }

}
void Labirinto::criaObstaculos()
{
    float x = Gerenciador_Grafico::getWIDTH()*2;
    float y = Gerenciador_Grafico::getHEIGHT();

    int m[12][22] = {   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    ///1 - Cria Tartaruga
    ///2 - Cria Cogumelo
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
                Cogumelo *a = new Cogumelo(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }

    ///tela2

    int m2[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    x = Gerenciador_Grafico::getWIDTH()*3;

    ///1 - Cria Tartaruga
    ///2 - Cria Cogumelo
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
                Cogumelo *a = new Cogumelo(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }

    ///tela3

    int m3[12][22] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///0
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///1
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///2
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///3
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},     ///4
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///5
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///6
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///7
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///9
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     ///10
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      ///11
                    };///0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1

    y = Gerenciador_Grafico::getHEIGHT()*2;

    ///1 - Cria Tartaruga
    ///2 - Cria Cogumelo
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
                Cogumelo *a = new Cogumelo(tamTerreno*j + x, tamTerreno*i + y, mec->getJogadorUm(), mec->getJogadorDois());
                adicionaObstaculo(a);
            }
        }
    }

}
void Labirinto::criaFundo()
{
    float x = Gerenciador_Grafico::getWIDTH()*2;
    float y = Gerenciador_Grafico::getHEIGHT();

    Background *b = new Background(x, y, "imagens/F2Lab/Background2.png");
    adicionaBackGround(b);

    ///tela 2
    x = Gerenciador_Grafico::getWIDTH()*3;

    Background *b2 = new Background(x, y, "imagens/F2Lab/Background3.png");
    adicionaBackGround(b2);

    ///tela 3
    y = Gerenciador_Grafico::getHEIGHT()*2;

    Background *b3 = new Background(x, y, "imagens/F2Lab/Background4.png");
    adicionaBackGround(b3);

}
