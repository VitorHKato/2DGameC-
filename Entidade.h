#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;

class Entidade
{
private:
    Vector2f tamanho;                               ///Tamanho do shape de colisão
    Vector2f posicao;                               ///Posição da entidade
    RenderWindow* window;                           ///Atributo janela para realizar o draw() na tela
protected:
    RectangleShape shape;                           ///Shape de colisão
    Texture textura;
    Sprite sprite;
public:
    Entidade(int x, int y);                         ///Passa a posicao da entidade como parametro
    ~Entidade();

    virtual void imprimir();                        ///Polimorfismo, todas as entidades são desenhadas da mesma forma
    virtual void update() = 0;                      ///Cada entidade têm sua própria atualização
    virtual void inicializa() = 0;                  ///Idem para inicialização
    virtual void animacao() = 0;                    ///Cada entidade têm sua própria animação

    ///Link com RenderWindow
    void setWindow(RenderWindow *window);
    RenderWindow* getWindow();

    void setShape(RectangleShape shape);
    RectangleShape getShape();
    void setTamanho(Vector2f tamanho);
    Vector2f getTamanho();
    void setPosicao(Vector2f posicao);
    Vector2f getPosicao();
    void setTextura(Texture textura);
    Texture getTextura();
    void setSprite(Sprite sprite);
    Sprite getSprite();

    ///Carrega imagem da entidade, passa o caminho do arquivo .png como parâmetro
    void loadSprite(const char* arq);
};
