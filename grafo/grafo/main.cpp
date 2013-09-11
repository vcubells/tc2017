//
//  main.cpp
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include "Grafo.h"

int main()
{
    
    Grafo *g = new Grafo();
    
    Vertice *v1 = new Vertice(1);
    Vertice *v2= new Vertice(2);
    Vertice *v3= new Vertice(3);
    Vertice *v4= new Vertice(4);
    Vertice *v5= new Vertice(5);
    Vertice *v6= new Vertice(6);
    
    g->adicionarVertice(v1);
    g->adicionarVertice(v2);
    g->adicionarVertice(v3);
    g->adicionarVertice(v4);
    g->adicionarVertice(v5);
    g->adicionarVertice(v6);
    
    g->adicionarArista(3, v1, v2);
    g->adicionarArista(3, v2, v3);
    g->adicionarArista(6, v3, v4);
    g->adicionarArista(1, v2, v4);
    g->adicionarArista(2, v2, v6);
    g->adicionarArista(4, v6, v5);
    g->adicionarArista(8, v6, v4);
    
    cout << *g;
    
    g->borraAristas(v6);
    
    cout << "Después de borrar aristas" << endl;
    
    cout << *g;
    
    
    delete g;
    
    return 0;
}