//
//  Vertice.cpp
//  grafo
//
//  Created by Vicente Cubells Nonell on 19/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include "Vertice.h"


ostream & operator <<(ostream & os, Vertice & v)
{
    os << v.info;
    
    return os;
}
