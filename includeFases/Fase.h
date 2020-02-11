#pragma once
#include <list>
#include "../includeFuncionamento/Mecanismo.h"
#include "../includeJogadores/JogadorUm.h"
#include "../includeJogadores/JogadorDois.h"
#include "../includeListas/ListaEntidades.h"
#include "../includeInimigos/MechaBomba.h"
#include "../includeObstaculos/Obstaculo.h"
#include "../includeTerrenosFloresta/TerrenoFloresta.h"
#include "../includeTerrenosFloresta/TerrenoFloresta2.h"
#include "../includeInimigos/Sapo.h"
#include "../includeInimigos/Bomba.h"
#include "../includeInimigos/Morcego.h"
#include "../includeInimigos/TorradaZombie.h"
#include "../includeObstaculos/Folha.h"
#include "../includeObstaculos/Fogo.h"
#include "../includeObstaculos/Cogumelo.h"
#include "../includeObstaculos/Tartaruga.h"
#include "../includeTerrenosFloresta/TerrenoFloresta3.h"
#include "../includeTerrenosFloresta/TerrenoFloresta4.h"
#include "../includeTerrenosLabirinto/TerrenoLabirinto.h"
#include "../includeTerrenosLabirinto/TerrenoLabirinto2.h"
#include "../includeTerrenosLabirinto/TerrenoLabirinto3.h"
#include "../includeTerrenosLabirinto/TerrenoLabirinto4.h"
#include "../includeTerrenosTemplo/TerrenoTemplo.h"
#include "../includeTerrenosTemplo/TerrenoTemplo2.h"
#include "../includeTerrenosTemplo/TerrenoTemplo3.h"
#include "../includeTerrenosTemplo/TerrenoTemplo4.h"
#include "../includeFuncionamento/Gerenciador_Grafico.h"
#include "../includeFundos/Background.h"
#include "../includeInimigos/Minotauro.h"
using namespace std;
using namespace Funcionamento;
using namespace Obstaculos;
using namespace TerrenosFloresta;
using namespace Inimigos;
using namespace TerrenosLabirinto;
using namespace TerrenosTemplo;
using namespace Fundos;

namespace Fases
{

    class Fase
    {
    protected:
        const static float tamTerreno;                 ///Tamanho fixo do terreno(multiplos de 50)

        Mecanismo *mec;                                 ///Composição com Mecanismo
    public:
        Fase(Mecanismo* mec);
        virtual ~Fase();

        ///Métodos para adicionar elementos nas respectivas listas do mecanismo e reconhecimento de janela
        virtual void adicionaTerreno(Terreno* t);
        virtual void adicionaIniNaoAtacavel(Inimigo* i);
        virtual void adicionaIniAtacavel(Inimigo* i);
        virtual void adicionaObstaculo(Obstaculo* o);
        virtual void adicionaBackGround(Background* b);
        virtual void adicionaForeGround(Background* f);

        ///Métodos para criar entidades da fase
        virtual void criaInimigos() = 0;
        virtual void criaTerreno() = 0;
        virtual void criaObstaculos() = 0;

        virtual void criaFundo() = 0;
    };
}

