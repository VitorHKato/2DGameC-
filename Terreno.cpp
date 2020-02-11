#include "Terreno.h"

Terreno::Terreno(int x, int y, bool wall) : Entidade(x, y)
{

}
Terreno::~Terreno()
{

}
void Terreno::setWall(bool wall)
{
    this->wall = wall;
}
bool Terreno::getWall()
{
    return wall;
}
