//
//  Arista.h
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __grafo__Arista__
#define __grafo__Arista__

#include "Vertice.h"

/* Clase Arista */
class Arista {
private:
    int peso;
    Vertice * destino;
    
public:
    Arista(int p, Vertice * adestino) : peso(p), destino(adestino)
    {
    }
    
    Vertice * getDestino()
    {
        return destino;
    }
    
    friend ostream & operator <<(ostream &, Arista *);
    
    ~Arista() {}
    
};

#endif /* defined(__grafo__Arista__) */
