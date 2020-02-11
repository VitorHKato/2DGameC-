#include "../includeFuncionamento/Gerenciador_Grafico.h"
using namespace Funcionamento;

const float Gerenciador_Grafico::HEIGHT(600);                    ///Altura
const float Gerenciador_Grafico::WIDTH(1100);                    ///e Largura da janela

Gerenciador_Grafico::Gerenciador_Grafico(Menu* m) : menu(m)
{
    fase = false;                                                ///Não foi dado pause
    pause = false;                                               ///Fase ainda n foi selecionada
    view.setSize(Vector2f(WIDTH, HEIGHT));
    view.setCenter(Vector2f(WIDTH/2, HEIGHT/2));
    view.setViewport(FloatRect(0, 0, 1, 1));
}
Gerenciador_Grafico::~Gerenciador_Grafico()
{

}
///Sets e Gets
void Gerenciador_Grafico::setJogadorUm(JogadorUm* playerOne)
{
    this->playerOne = playerOne;
}
void Gerenciador_Grafico::setJogadorDois(JogadorDois* playerTwo)
{
    this->playerTwo = playerTwo;
}
void Gerenciador_Grafico::setWindow(RenderWindow *window)
{
    this->window = window;
}
void Gerenciador_Grafico::setListaEntidades(ListaEntidades* listaEntidades)
{
    this->listaEntidades = listaEntidades;
}
void Gerenciador_Grafico::setMecanismo(Mecanismo* mec)
{
    this->mec = mec;
}
void Gerenciador_Grafico::setControle(Controle* control)
{
    this->control = control;
}
const float Gerenciador_Grafico::getHEIGHT()
{
    return HEIGHT;
}
const float Gerenciador_Grafico::getWIDTH()
{
    return WIDTH;
}
///
void Gerenciador_Grafico::loopPrincipal()
{
    int aux;                                                ///Auxiliar para armazenar a opção do menuPrincipal
    int aux2;                                               ///Auxiliar para armazenar a opção do menuFases

    while(window->isOpen())                                 ///Uso do link, método de window é utilizado
    {
        while(window->pollEvent(event))
        {
            if(event.type == Event::Closed)
                window->close();

            pausar();
            control->comandos(event);                           ///Utilização do link com Controle

        }
        tela();                                                 ///Identifica qual tela do jogo mostrar
        if(!pause)                                              ///Se a tecla de pause não estiver pressionada
        {
            ///Identifica escolhas do menu e coloca os jogadores na fase escolhida
            if(menu->getAtivo())
            {
                aux = menu->menuPrincipal(window);
                aux2 = menu->menuFases(window);

                playerTwo->setPosicao(Vector2f(-50, -50));
                if(aux2 == 0)
                {
                    menu->setAtivo(false);
                    fase = true;
                    playerOne->setPosicao(Vector2f(100, 500));
                    if(aux ==  1)
                        playerTwo->setPosicao(Vector2f(100, 500));

                }
                else if(aux2 == 1)
                {
                    menu->setAtivo(false);
                    fase = true;
                    playerOne->setPosicao(Vector2f(100, 500));
                    if(aux == 1)
                        playerTwo->setPosicao(Vector2f(100, 500));
                }
                else if(aux2 == 2)
                {
                    menu->setAtivo(false);
                    fase = true;
                    playerOne->setPosicao(Vector2f(50 + Gerenciador_Grafico::getWIDTH()*2, 50 + Gerenciador_Grafico::getHEIGHT()));
                    if(aux == 1)
                        playerTwo->setPosicao(Vector2f(50 + Gerenciador_Grafico::getWIDTH()*2, 50 + Gerenciador_Grafico::getHEIGHT()));
                }
                else if(aux2 == 3)
                {
                    menu->setAtivo(false);
                    fase = true;
                    playerOne->setPosicao(Vector2f(1050 + Gerenciador_Grafico::getWIDTH()*2, 550 + Gerenciador_Grafico::getHEIGHT()*2));
                    if(aux == 1)
                        playerTwo->setPosicao(Vector2f(1050 + Gerenciador_Grafico::getWIDTH()*2, 550 + Gerenciador_Grafico::getHEIGHT()*2));
                }
                else if(aux2 == 4)
                {
                    menu->setAtivo(false);
                    fase = true;
                    playerOne->setPosicao(Vector2f(50 , 50 + Gerenciador_Grafico::getHEIGHT()*3));
                    if(aux == 1)
                        playerTwo->setPosicao(Vector2f(50 , 50 + Gerenciador_Grafico::getHEIGHT()*3));                }
                }
                else if(menu->menuPrincipal(window) ==  2)
                {
                    window->close();
                }
                else if(menu->menuPrincipal(window) ==  -2)
                {
                    window->close();
                }

            if(fase)
            {
                update();                                               ///Att da imagem
                mec->gerenciaColisoes();                                ///Utilização do link com Mecanismo
                control->movimentacao();                                ///Utilização do link com Controle
            }
        }
    }
}
void Gerenciador_Grafico::update()
{
    window->clear(Color::Cyan);
    window->setView(view);
    mec->percorreListaBackGrounds();
    listaEntidades->draw();                                 ///Utilização do link, Gerenciador_Grafico acessa método da ListaEntidades
    mec->percorreListaForeGrounds();
    window->display();
}
void Gerenciador_Grafico::tela()
{
    ///Intervalos determinam qual tela mostrar, com base na posição dos jogadores

    ///tela 1
    if(((mec->getJogadorUm()->getPosicao().x < WIDTH) && (mec->getJogadorUm()->getPosicao().y < HEIGHT))
       || ((mec->getJogadorDois()->getPosicao().x < WIDTH) && (mec->getJogadorDois()->getPosicao().y < HEIGHT)))
    {
        view.setCenter(Vector2f(WIDTH/2, HEIGHT/2));
    }
    ///tela 2
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH) && (mec->getJogadorUm()->getPosicao().y < HEIGHT)
            && (mec->getJogadorUm()->getPosicao().x < WIDTH*2)) || ((mec->getJogadorDois()->getPosicao().x < WIDTH*2)
            && (mec->getJogadorDois()->getPosicao().x > WIDTH) && (mec->getJogadorDois()->getPosicao().y < HEIGHT)))
    {
        view.setCenter(Vector2f(WIDTH/2 + WIDTH, HEIGHT/2));
    }
    ///tela 3
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH*2) && (mec->getJogadorUm()->getPosicao().y < HEIGHT)
            && (mec->getJogadorUm()->getPosicao().x < WIDTH*3)) || ((mec->getJogadorDois()->getPosicao().x < WIDTH*3)
            && (mec->getJogadorDois()->getPosicao().x > WIDTH*2) && (mec->getJogadorDois()->getPosicao().y < HEIGHT)))
    {
        view.setCenter(Vector2f(WIDTH*2 + WIDTH/2, HEIGHT/2));
    }
    ///tela 4
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH*2) && (mec->getJogadorUm()->getPosicao().x < WIDTH*3)
            && (mec->getJogadorUm()->getPosicao().y > HEIGHT) && (mec->getJogadorUm()->getPosicao().y < HEIGHT*2))
            || ((mec->getJogadorDois()->getPosicao().x > WIDTH*2) && (mec->getJogadorDois()->getPosicao().x < WIDTH*3)
            && (mec->getJogadorDois()->getPosicao().y > HEIGHT) && (mec->getJogadorDois()->getPosicao().y < HEIGHT*2)))
    {
        view.setCenter(Vector2f(WIDTH*2 + WIDTH/2, HEIGHT/2 + HEIGHT));
    }
    ///tela 5
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH*3) && (mec->getJogadorUm()->getPosicao().x < WIDTH*4)
            && (mec->getJogadorUm()->getPosicao().y > HEIGHT) && (mec->getJogadorUm()->getPosicao().y < HEIGHT*2))
            || ((mec->getJogadorDois()->getPosicao().y > HEIGHT) && (mec->getJogadorDois()->getPosicao().y < HEIGHT*2))
            && (mec->getJogadorDois()->getPosicao().x > WIDTH*3) && (mec->getJogadorDois()->getPosicao().x < WIDTH*4))
    {
        view.setCenter(Vector2f(WIDTH*3 + WIDTH/2, HEIGHT/2 + HEIGHT));
    }
    ///tela 6
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH*3) && (mec->getJogadorUm()->getPosicao().x < WIDTH*4)
            && (mec->getJogadorUm()->getPosicao().y > HEIGHT*2) && (mec->getJogadorUm()->getPosicao().y < HEIGHT*3))
            || ((mec->getJogadorDois()->getPosicao().y < HEIGHT*3) && (mec->getJogadorDois()->getPosicao().y > HEIGHT*2)
            && (mec->getJogadorDois()->getPosicao().x > WIDTH*3) && (mec->getJogadorDois()->getPosicao().x < WIDTH*4)))
    {
        view.setCenter(Vector2f(WIDTH*3 + WIDTH/2, HEIGHT/2 + HEIGHT*2));
    }
    ///tela 7
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH*2) && (mec->getJogadorUm()->getPosicao().x < WIDTH*3)
            && (mec->getJogadorUm()->getPosicao().y > HEIGHT*2) && (mec->getJogadorUm()->getPosicao().y < HEIGHT*3))
            || ((mec->getJogadorDois()->getPosicao().y < HEIGHT*3) && (mec->getJogadorDois()->getPosicao().x > WIDTH*2)
            && (mec->getJogadorDois()->getPosicao().x < WIDTH*3) && (mec->getJogadorDois()->getPosicao().y > HEIGHT*2)))
    {
        view.setCenter(Vector2f(WIDTH*2 + WIDTH/2, HEIGHT/2 + HEIGHT*2));
    }
    ///tela 8
    else if(((mec->getJogadorUm()->getPosicao().x > WIDTH) && (mec->getJogadorUm()->getPosicao().x < WIDTH*2)
            && (mec->getJogadorUm()->getPosicao().y > HEIGHT*2) && (mec->getJogadorUm()->getPosicao().y < HEIGHT*3))
            || ((mec->getJogadorDois()->getPosicao().y < HEIGHT*3) && (mec->getJogadorDois()->getPosicao().x > WIDTH)
            && (mec->getJogadorDois()->getPosicao().x < WIDTH*2) && (mec->getJogadorDois()->getPosicao().y > HEIGHT*2)))
    {
        view.setCenter(Vector2f(WIDTH + WIDTH/2, HEIGHT/2 + HEIGHT*2));
    }
    ///tela 9
    else if(((mec->getJogadorUm()->getPosicao().x < WIDTH) && (mec->getJogadorUm()->getPosicao().y > HEIGHT*2)
            && (mec->getJogadorUm()->getPosicao().y < HEIGHT*3)) || ((mec->getJogadorDois()->getPosicao().y < HEIGHT*3)
            && (mec->getJogadorDois()->getPosicao().x < WIDTH) && (mec->getJogadorDois()->getPosicao().y > HEIGHT*2)))
    {
        view.setCenter(Vector2f(WIDTH/2, HEIGHT/2 + HEIGHT*2));
    }
    ///tela 10
    else if(((mec->getJogadorUm()->getPosicao().x < WIDTH) && (mec->getJogadorUm()->getPosicao().y > HEIGHT*3)
            && (mec->getJogadorUm()->getPosicao().y < HEIGHT*4)) || ((mec->getJogadorDois()->getPosicao().y < HEIGHT*4)
            && (mec->getJogadorDois()->getPosicao().x < WIDTH) && (mec->getJogadorDois()->getPosicao().y > HEIGHT*3)))
    {
        view.setCenter(Vector2f(WIDTH/2, HEIGHT/2 + HEIGHT*3));
    }
}
void Gerenciador_Grafico::pausar()
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::P && !pause)
        pause = true;
    else if(event.type == Event::KeyPressed && event.key.code == Keyboard::P && pause)
        pause = false;
}
