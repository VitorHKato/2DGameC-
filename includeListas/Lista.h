/*
    Lista encadeada implementada a mão, para substituir o "<list>"
*/
#pragma once
#include "../Entidade.h"
#include <iostream>

namespace Listas
{
    class Lista
    {
    protected:
        class Elemento
        {
        public:
            ///Ponteiro da posicao atual e da seguinte
            Entidade* entidade;
            Elemento* pProx;

        public:
            Elemento()
            {
                entidade = NULL;
                pProx = NULL;
            }
            ~Elemento()
            {

            }
        };
        ///Ponteiro da primeira e ultima posicao da lista
        Elemento* pPri;
        Elemento* pUlt;
    public:
        Lista()
        {
            pPri = NULL;
            pUlt = NULL;
        }
        ~Lista()
        {

        }
        void addEntidade(Entidade* novaEntidade)        ///Adiciona entidades à lista
        {
            ///temporario recebe o atual
            Elemento* novoElemento = new Elemento;
            novoElemento->entidade = novaEntidade;

            ///Se for o unico da lista
            if (pPri == NULL)
            {
                pPri = novoElemento;
                pUlt = novoElemento;
            }
            ///Se nao, começa da primeira posicao e faz o ultimo apontar para o atual
            else
            {
                Elemento* i = pPri;

                while (i != pUlt) i = i->pProx;

                ///Consistencia para a ultima posicao
                i->pProx = novoElemento;
                pUlt = novoElemento;                    ///atualiza o ultimo
            }
        }
        void imprimir()             ///Percorre toda a lista e chama o método imprimir das entidades polimorficamente
        {
            if(pPri)                ///se não estiver vazia
            {
                Elemento* i = pPri;
                while (i != pUlt)
                {
                    i->entidade->imprimir();            ///Polimorfimo através do método update, chamado dentro do imprimir
                    i = i->pProx;
                }
                i->entidade->imprimir();
            }
            else
                std::cout << "Lista Vazia." << std::endl;
        }
    };
}
