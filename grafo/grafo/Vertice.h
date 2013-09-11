//
//  Vertice.h
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __grafo__Vertice__
#define __grafo__Vertice__

#include <iostream>
using namespace std;

/* Clase Vertice */
class Vertice {
private:
    int info;
    
public:
    Vertice(int i) : info(i)
    {
    }
    
    friend ostream & operator <<(ostream &, Vertice &);
    
    ~Vertice() {};
    
};

#endif /* defined(__grafo__Vertice__) */
