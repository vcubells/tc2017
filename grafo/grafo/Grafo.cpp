//
//  Grafo.cpp
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include "Grafo.h"

void Grafo::adicionarVertice(Vertice *vertice)
{
    vertices[vertice] = list<Arista * >();
}

void Grafo::adicionarArista(int peso, Vertice * origen, Vertice * destino)
{
    Arista *a = new Arista(peso, destino);
    vertices[origen].push_back(a);
}

ostream & operator <<(ostream & os , Grafo & g)
{
    map <Vertice * , list<Arista * > >::iterator
    inicio (g.vertices.begin()),
    fin (g.vertices.end());
    
    for(; inicio != fin; ++inicio)
    {
        
        os << "Vertice " << *(inicio->first) << endl;
        copy(inicio->second.begin(), inicio->second.end(), ostream_iterator<Arista *>(os, "\n"));
    }
    
    return os;
}

Grafo::~Grafo()
{
    vertices.clear();
}


void Grafo::borraAristas(Vertice * v)
{
    list < Arista *> * aristas;
    
    map <Vertice *, list <Arista *> >::iterator
    mi(vertices.begin()),
    mf(vertices.end());
    
    for (; mi != mf; ++mi) {
        
        if (mi->first != v) {

            aristas = &( mi->second);
            
            list<Arista *>::iterator
            li(aristas->begin()),
            lf(aristas->end());
            
            for (; li != lf; ++li) {
                if ((*li)->getDestino() == v)
                    aristas->erase(li);
            }
        }
    }
}

bool compare(pair<Vertice *, int> uno, pair<Vertice *, int> dos )
{
    return uno.second < dos.second;
}

void Grafo::Prim(Vertice * inicio)
{
    map <Vertice *, info> tabla;
    map <Vertice *, int> Q;
    list <Arista *> aristas;
    Vertice * adyacente;
    
    map <Vertice *, list <Arista *> >::iterator
    mi(vertices.begin()),
    mf(vertices.end());
    
    for (; mi != mf; ++mi) {
        
        if (mi->first != inicio)
            tabla[mi->first].distancia = 10000;
        else
            tabla[mi->first].distancia = 0;

        tabla[mi->first].vertice = NULL;
        
        Q[mi->first] = tabla[mi->first].distancia;
    }
    
    /* Ordenar cola */
    
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        
        /* Para todos los adyacentes */
        aristas = vertices[temp.vertice];
        
        list<Arista *>::iterator
        li(aristas.begin()),
        lf(aristas.end());
        
        for (; li != lf; ++li) {
            adyacente = (*li)->getDestino();
            if (find(Q.front(), Q.back(), )) {
                <#statements#>
            }
        }
        
        Q.
    }
    
    
}
