#include "../includeFuncionamento/Mecanismo.h"
using namespace Funcionamento;

Mecanismo::Mecanismo(ListaEntidades *l, RenderWindow* w, JogadorUm* playerOne, JogadorDois* playerTwo) : listaEntidades(l),
window(w), playerOne(playerOne), playerTwo(playerTwo)
{

}
Mecanismo::~Mecanismo()
{

}
                                                                         ///Sets e Gets
RenderWindow* Mecanismo::getWindow()
{
    return window;
}
JogadorUm* Mecanismo::getJogadorUm()
{
    return playerOne;
}
ListaEntidades* Mecanismo::getListaEntidades()
{
    return listaEntidades;
}
JogadorDois* Mecanismo::getJogadorDois()
{
    return playerTwo;
}                                                                           ///
                                                                            ///Listas (começo)
void Mecanismo::addListaInimigosNaoAtacaveis(Inimigo* novoInimigo)
{
        listaIniNaoAtacaveis.push_front(novoInimigo);
        listaEntidades->addEntidade(novoInimigo);
        novoInimigo->setWindow(window);
}
void Mecanismo::addListaInimigosAtacaveis(Inimigo* novoInimigo)
{
        listaIniAtacaveis.push_front(novoInimigo);
        listaEntidades->addEntidade(novoInimigo);
        novoInimigo->setWindow(window);
}
void Mecanismo::addListaObstaculos(Obstaculo* novoObstaculo)
{
        listaObstaculos.push_front(novoObstaculo);
        listaEntidades->addEntidade(novoObstaculo);
        novoObstaculo->setWindow(window);
}
void Mecanismo::addListaTerreno(Terreno* novoBloco)
{
        listaTerreno.push_front(novoBloco);
        listaEntidades->addEntidade(novoBloco);
        novoBloco->setWindow(window);
}
void Mecanismo::addListaBackGrounds(Background* novoBackGround)
{
    listaBackGrounds.push_front(novoBackGround);
    novoBackGround->setWindow(window);
}
void Mecanismo::addListaForeGrounds(Background* novoForeGround)
{
    listaForeGrounds.push_front(novoForeGround);
    novoForeGround->setWindow(window);
}
void Mecanismo::percorreListaBackGrounds()
{
    for(i_BackG = listaBackGrounds.begin(); i_BackG != listaBackGrounds.end(); i_BackG++)
    {
        (*i_BackG)->imprimir();
    }
}
void Mecanismo::percorreListaForeGrounds()
{
    for(i_ForeG = listaForeGrounds.begin(); i_ForeG != listaForeGrounds.end(); i_ForeG++)
    {
        (*i_ForeG)->imprimir();
    }
}
                                                                            ///
                                                                            ///Métodos de Colisão
void Mecanismo::gerenciaColisoes()
{
    ///players x inimigos N atacaveis
    for(i_iniNaoAtacaveis = listaIniNaoAtacaveis.begin(); i_iniNaoAtacaveis != listaIniNaoAtacaveis.end(); i_iniNaoAtacaveis++)
    {
        colisaoInimigosNaoAtacaveis(*i_iniNaoAtacaveis, playerOne);
        colisaoInimigosNaoAtacaveis(*i_iniNaoAtacaveis, playerTwo);
    }

    ///players x inimigos atacaveis
    for(i_iniAtacaveis = listaIniAtacaveis.begin(); i_iniAtacaveis != listaIniAtacaveis.end(); i_iniAtacaveis++)
    {
        colisaoInimigosAtacaveis(*i_iniAtacaveis, playerOne);
        colisaoInimigosAtacaveis(*i_iniAtacaveis, playerTwo);
    }

    ///players x obstaculos
    for(i_obstaculos = listaObstaculos.begin(); i_obstaculos != listaObstaculos.end(); i_obstaculos++)
    {
        colisaoObstaculos(*i_obstaculos, playerOne);
        colisaoObstaculos(*i_obstaculos, playerTwo);
    }

    ///todos os personagens com o terreno
    for(i_terreno = listaTerreno.begin(); i_terreno != listaTerreno.end(); i_terreno++)
    {
        ///players x terreno
        colisaoTerrenoPlayer(*i_terreno, playerOne);
        colisaoTerrenoPlayer(*i_terreno, playerTwo);

        ///ini n atacaveis x terreno
        for(i_iniNaoAtacaveis = listaIniNaoAtacaveis.begin(); i_iniNaoAtacaveis != listaIniNaoAtacaveis.end(); i_iniNaoAtacaveis++)
        {
            colisaoTerreno(*i_terreno, *i_iniNaoAtacaveis);
        }

        ///inimigos atacaveis x terreno
        for(i_iniAtacaveis = listaIniAtacaveis.begin(); i_iniAtacaveis != listaIniAtacaveis.end(); i_iniAtacaveis++)
        {
            colisaoTerreno(*i_terreno, *i_iniAtacaveis);
        }

        ///obstaculos x terreno
        for(i_obstaculos = listaObstaculos.begin(); i_obstaculos != listaObstaculos.end(); i_obstaculos++)
        {
            colisaoTerreno(*i_terreno, *i_obstaculos);
        }
    }
}
void Mecanismo::colisaoTerrenoPlayer(Terreno* terreno, Jogador* player)
{
    if(terreno->getPosicao().x < player->getPosicao().x + player->getTamanho().x &&         ///Verifica se está colidindo
    terreno->getPosicao().x + terreno->getTamanho().x > player->getPosicao().x &&
    terreno->getPosicao().y < player->getPosicao().y + player->getTamanho().y &&
    terreno->getTamanho().y + terreno->getPosicao().y > player->getPosicao().y)
    {
        player->setIsJumping(false);           ///Se o jogador está colidindo com o terreno, significa q não está no ar

        float distBotATopB = abs(player->getPosicao().y + player->getTamanho().y - terreno->getPosicao().y);
        float distTopABotB = abs(player->getPosicao().y - terreno->getPosicao().y - terreno->getTamanho().y);
        float distRightALeftB = abs(player->getPosicao().x + player->getTamanho().x - terreno->getPosicao().x);
        float distLeftBRightA = abs(player->getPosicao().x - terreno->getPosicao().x - terreno->getTamanho().x);

        if (distBotATopB < distTopABotB && distBotATopB <= distRightALeftB && distBotATopB < distLeftBRightA)
        {
            player->setPosicao(Vector2f(player->getPosicao().x, terreno->getPosicao().y - player->getTamanho().y));
            player->setVelocidade(Vector2f(player->getVelocidade().x, 0));
        }
        else if (distTopABotB < distBotATopB && distTopABotB <= distRightALeftB && distTopABotB < distLeftBRightA)
            player->setPosicao(Vector2f(player->getPosicao().x, terreno->getPosicao().y + player->getTamanho().y));
        else if (distRightALeftB < distTopABotB && distRightALeftB <= distBotATopB && distRightALeftB < distLeftBRightA)        ///direita
            player->setPosicao(Vector2f(terreno->getPosicao().x - player->getTamanho().x, player->getPosicao().y));
        else if (distLeftBRightA < distTopABotB && distLeftBRightA <= distRightALeftB && distLeftBRightA < distBotATopB)        ///esquerda
            player->setPosicao(Vector2f(terreno->getPosicao().x + terreno->getTamanho().x, player->getPosicao().y));

    }

}
void Mecanismo::colisaoTerreno(Terreno* terreno, Personagem* p)     ///Personagens
{
    if(terreno->getPosicao().x < p->getPosicao().x + p->getTamanho().x &&
    terreno->getPosicao().x + terreno->getTamanho().x > p->getPosicao().x &&
    terreno->getPosicao().y < p->getPosicao().y + p->getTamanho().y &&
    terreno->getTamanho().y + terreno->getPosicao().y > p->getPosicao().y)
    {
        float distBotATopB = abs(p->getPosicao().y + p->getTamanho().y - terreno->getPosicao().y);
        float distTopABotB = abs(p->getPosicao().y - terreno->getPosicao().y - terreno->getTamanho().y);
        float distRightALeftB = abs(p->getPosicao().x + p->getTamanho().x - terreno->getPosicao().x);
        float distLeftBRightA = abs(p->getPosicao().x - terreno->getPosicao().x - terreno->getTamanho().x);

        if (distBotATopB < distTopABotB && distBotATopB <= distRightALeftB && distBotATopB < distLeftBRightA)
        {
            p->setPosicao(Vector2f(p->getPosicao().x, terreno->getPosicao().y - p->getTamanho().y));
            p->setVelocidade(Vector2f(p->getVelocidade().x, 0));
        }
        else if (distTopABotB < distBotATopB && distTopABotB <= distRightALeftB && distTopABotB < distLeftBRightA)
            p->setPosicao(Vector2f(p->getPosicao().x, terreno->getPosicao().y + p->getTamanho().y));
        else if (distRightALeftB < distTopABotB && distRightALeftB <= distBotATopB && distRightALeftB < distLeftBRightA)        ///direita
        {
            if(p->getOlhandoDireita() && terreno->getWall())
                p->setOlhandoDireita(false);
        }
        else if (distLeftBRightA < distTopABotB && distLeftBRightA <= distRightALeftB && distLeftBRightA < distBotATopB)        ///esquerda
        {
            if(!p->getOlhandoDireita() && terreno->getWall())
                p->setOlhandoDireita(true);
        }

    }
}
///Colisões com os jogadores
void Mecanismo::colisaoInimigosNaoAtacaveis(Inimigo* inimigo, Jogador* player)
{
    if(inimigo->getShape().getGlobalBounds().intersects(player->getShape().getGlobalBounds()))
    {
        player->setMorreu(true);
    }
}
void Mecanismo::colisaoInimigosAtacaveis(Inimigo* inimigo, Jogador* player)
{
    float pY = player->getPosicao().y + player->getTamanho().y;
    float i = inimigo->getPosicao().y;

    if(player->getShape().getGlobalBounds().intersects(inimigo->getShape().getGlobalBounds())
       && (pY < i + 10))                                                                        ///Intervalo para identificar colisao por cima
    {
        player->setVelocidade(Vector2f(player->getVelocidade().x, -23));
        inimigo->setMorreu(true);
    }
    else if(player->getShape().getGlobalBounds().intersects(inimigo->getShape().getGlobalBounds()))
    {
        player->setMorreu(true);
    }


    /*if(player->getShape().getGlobalBounds().intersects(inimigo->getShape().getGlobalBounds())
       && (aux <= player->getTamanho().x))
    {
        player->setPosicao(Vector2f(50, 50));
        cout << "Morreu2" << endl;
    }
    else if((player->getShape().getGlobalBounds().intersects(inimigo->getShape().getGlobalBounds()))
       &&(player->getPosicao().y - player->getTamanho().y < inimigo->getPosicao().y + inimigo->getTamanho().y))
    {
        player->setVelocidade(Vector2f(player->getVelocidade().x, -23));
        cout << "matou" << endl;
    }
    else if(player->getShape().getGlobalBounds().intersects(inimigo->getShape().getGlobalBounds())
       && (player->getPosicao().y + player->getTamanho().y > inimigo->getPosicao().y + inimigo->getTamanho().y))
    {
        player->setPosicao(Vector2f(50, 50));
        cout << "Morreu" << endl;
    }*/
}
void Mecanismo::colisaoObstaculos(Obstaculo* obstaculo, Jogador* player)
{
    if(obstaculo->getShape().getGlobalBounds().intersects(player->getShape().getGlobalBounds()))
    {
        player->setMorreu(true);
    }
}

