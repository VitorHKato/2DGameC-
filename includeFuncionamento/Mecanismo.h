#pragma once
#include "../Entidade.h"
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeObstaculos/Obstaculo.h"
#include <list>
#include "../includeInimigos/Inimigo.h"
#include "../includeListas/ListaEntidades.h"
#include "../Terreno.h"
#include "../includeFundos/Background.h"
#include <cmath>
using namespace std;
using namespace Obstaculos;
using namespace Listas;
using namespace Jogadores;
using namespace Inimigos;
using namespace Fundos;

namespace Funcionamento
{
    class Mecanismo
    {
    private:
        ListaEntidades* listaEntidades;
        JogadorUm* playerOne;
        JogadorDois* playerTwo;
        RenderWindow *window;
    protected:
        list<Inimigo*> listaIniNaoAtacaveis;                            ///Lista de Inimigos "N�o atac�veis"
        list<Inimigo*>::iterator i_iniNaoAtacaveis;

        list<Inimigo*> listaIniAtacaveis;                               ///Lista de Inimigos "Atac�veis"
        list<Inimigo*>::iterator i_iniAtacaveis;

        list<Obstaculo*> listaObstaculos;                               ///Lista de Obst�culos
        list<Obstaculo*>::iterator i_obstaculos;

        list<Terreno*> listaTerreno;                                    ///Lista do Terreno
        list<Terreno*>::iterator i_terreno;

        list<Background*> listaBackGrounds;                             ///Lista de Backgrounds
        list<Background*>::iterator i_BackG;

        list<Background*> listaForeGrounds;                             ///Lista de Foregrounds
        list<Background*>::iterator i_ForeG;
    public:
        Mecanismo(ListaEntidades* l, RenderWindow* w, JogadorUm* playerOne, JogadorDois* playerTwo);
        ~Mecanismo();

        ///Gets
        JogadorUm* getJogadorUm();
        JogadorDois* getJogadorDois();
        ListaEntidades* getListaEntidades();
        RenderWindow* getWindow();

        ///M�todos de adicionar
        void addListaInimigosNaoAtacaveis(Inimigo* novoInimigo);
        void addListaInimigosAtacaveis(Inimigo* novoInimigo);
        void addListaObstaculos(Obstaculo* novoObstaculo);
        void addListaTerreno(Terreno* novoBloco);
        void addListaBackGrounds(Background* novoBackGround);
        void addListaForeGrounds(Background* novoForeGround);

        ///M�todos de percorrer e mostrar backgrounds e foregrounds
        void percorreListaBackGrounds();
        void percorreListaForeGrounds();

        ///M�todos de Colis�o
        void colisaoTerreno(Terreno* terreno, Personagem* p);
        void colisaoTerrenoPlayer(Terreno* terreno, Jogador* player);
        void colisaoInimigosNaoAtacaveis(Inimigo* inimigo, Jogador* player);
        void colisaoInimigosAtacaveis(Inimigo* inimigo, Jogador* player);
        void colisaoObstaculos(Obstaculo* obstaculo, Jogador* player);
        void gerenciaColisoes();                        ///Verifica as colis�es e chama os respectivos m�todos de cada entidade

    };
}
