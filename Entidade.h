#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;

class Entidade
{
private:
    Vector2f tamanho;                               ///Tamanho do shape de colis�o
    Vector2f posicao;                               ///Posi��o da entidade
    RenderWindow* window;                           ///Atributo janela para realizar o draw() na tela
protected:
    RectangleShape shape;                           ///Shape de colis�o
    Texture textura;
    Sprite sprite;
public:
    Entidade(int x, int y);                         ///Passa a posicao da entidade como parametro
    ~Entidade();

    virtual void imprimir();                        ///Polimorfismo, todas as entidades s�o desenhadas da mesma forma
    virtual void update() = 0;                      ///Cada entidade t�m sua pr�pria atualiza��o
    virtual void inicializa() = 0;                  ///Idem para inicializa��o
    virtual void animacao() = 0;                    ///Cada entidade t�m sua pr�pria anima��o

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

    ///Carrega imagem da entidade, passa o caminho do arquivo .png como par�metro
    void loadSprite(const char* arq);
};
