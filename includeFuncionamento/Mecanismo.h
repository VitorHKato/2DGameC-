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
        list<Inimigo*> listaIniNaoAtacaveis;                            ///Lista de Inimigos "Não atacáveis"
        list<Inimigo*>::iterator i_iniNaoAtacaveis;

        list<Inimigo*> listaIniAtacaveis;                               ///Lista de Inimigos "Atacáveis"
        list<Inimigo*>::iterator i_iniAtacaveis;

        list<Obstaculo*> listaObstaculos;                               ///Lista de Obstáculos
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

        ///Métodos de adicionar
        void addListaInimigosNaoAtacaveis(Inimigo* novoInimigo);
        void addListaInimigosAtacaveis(Inimigo* novoInimigo);
        void addListaObstaculos(Obstaculo* novoObstaculo);
        void addListaTerreno(Terreno* novoBloco);
        void addListaBackGrounds(Background* novoBackGround);
        void addListaForeGrounds(Background* novoForeGround);

        ///Métodos de percorrer e mostrar backgrounds e foregrounds
        void percorreListaBackGrounds();
        void percorreListaForeGrounds();

        ///Métodos de Colisão
        void colisaoTerreno(Terreno* terreno, Personagem* p);
        void colisaoTerrenoPlayer(Terreno* terreno, Jogador* player);
        void colisaoInimigosNaoAtacaveis(Inimigo* inimigo, Jogador* player);
        void colisaoInimigosAtacaveis(Inimigo* inimigo, Jogador* player);
        void colisaoObstaculos(Obstaculo* obstaculo, Jogador* player);
        void gerenciaColisoes();                        ///Verifica as colisões e chama os respectivos métodos de cada entidade

    };
}
