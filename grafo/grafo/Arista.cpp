//
//  Arista.cpp
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include "Arista.h"

ostream & operator <<(ostream & os, Arista * a)
{
    os << " -> " << a->peso << " -> " << *(a->destino);
    
    return os;
}
