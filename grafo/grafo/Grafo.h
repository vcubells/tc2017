//
//  Grafo.h
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __grafo__Grafo__
#define __grafo__Grafo__


#include <iterator>
#include <list>
#include <map>
#include <queue>

#include "Arista.h"

typedef struct {
    int distancia;
    Vertice * vertice;
} info ;

class Grafo {
private:
    map < Vertice *, list< Arista * > > vertices;
    
public:
    Grafo(){}
    void adicionarVertice(Vertice * vertice);
    void adicionarArista(int peso, Vertice * origen, Vertice * destino);
    
    void borraAristas(Vertice *);
    void Prim(Vertice *);
    
    friend ostream & operator <<(ostream & os , Grafo & g);
    ~Grafo();
};


#endif /* defined(__grafo__Grafo__) */
