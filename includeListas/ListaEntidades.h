#pragma once
#include "../Entidade.h"
#include "../includeListas/Lista.h"
#include "SFML/Graphics.hpp"
using namespace sf;

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista entidades;                                    ///Composicao com Lista
    public:
        ListaEntidades();
        ~ListaEntidades();

        ///Usa os métodos implementados na Lista
        void addEntidade(Entidade* novaEntidade);
        void draw();
    };
}

