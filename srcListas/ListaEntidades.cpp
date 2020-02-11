#include "../includeListas/ListaEntidades.h"
using namespace Listas;

ListaEntidades::ListaEntidades()
{

}
ListaEntidades::~ListaEntidades()
{

}
void ListaEntidades::addEntidade(Entidade* novaEntidade)
{
    entidades.addEntidade(novaEntidade);
}
void ListaEntidades::draw()
{
    entidades.imprimir();
}

