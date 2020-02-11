#include "../includeFuncionamento/Jogo.h"
using namespace Funcionamento;

Jogo::Jogo()
{
    janela();                                    ///Inicializa os atributos da janela
    inicializa();                                ///Aloca as instâncias
    relacoes();                                  ///Realiza as relações de associação
    gerenciador->loopPrincipal();                ///Chama o loop principal do jogo
}
Jogo::~Jogo()
{

}
void Jogo::janela()
{
    ///Uso dos atributos estáticos contidos no Gerenciador_Grafico
    window = new RenderWindow(VideoMode(Gerenciador_Grafico::getWIDTH(), Gerenciador_Grafico::getHEIGHT()), "Tabby Cat");

    window->setVerticalSyncEnabled(true);
    window->setKeyRepeatEnabled(true);
    window->setFramerateLimit(60);
}
void Jogo::inicializa()
{
    menu = new Menu();
    gerenciador = new Gerenciador_Grafico(menu);
    listaEntidades = new ListaEntidades();
    playerOne = new JogadorUm(100, 450);
    playerTwo = new JogadorDois(100, 450);
    mec = new Mecanismo(listaEntidades, window, playerOne, playerTwo);
    faseUmFloresta = new Floresta(mec);
    faseDoisLabirinto = new Labirinto(mec);
    faseTresTemplo = new Templo(mec);
    control = new Controle();
    ///Já adiciona os 2 players à lista
    listaEntidades->addEntidade(playerOne);
    listaEntidades->addEntidade(playerTwo);
}
void Jogo::relacoes()
{
    ///Associações do gerenciador
    gerenciador->setListaEntidades(listaEntidades);
    gerenciador->setMecanismo(mec);
    gerenciador->setControle(control);
    gerenciador->setWindow(window);
    gerenciador->setJogadorUm(playerOne);
    gerenciador->setJogadorDois(playerTwo);

    ///Associações Jogadores
    playerOne->setWindow(window);
    playerTwo->setWindow(window);

    ///Associações Control
    control->setJogadorUm(playerOne);
    control->setJogadorDois(playerTwo);

}

