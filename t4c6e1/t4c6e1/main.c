//  Algoritmo de Floyd-Warshall
//  main.c
//  t4c6e1
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 9

void Floyd(int C[N][N], int A[N][N]);
void imprime(int M[N][N]);

int main()
{
    int C[N][N];
    int A[N][N];
    
    /* Inicializar C */
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if ( i == j) C[i][j]=0;
            else C[i][j]=1000;
    
    C[0][1] = 6;
    C[0][3] = 10;
    
    C[1][0] = 6;
    C[3][0] = 10;
    
    C[1][2] = 5;
    C[1][4] = 10;
    
    C[2][1] = 5;
    C[4][1] = 10;
    
    C[3][4] = 9;
    C[3][6] = 5;
    
    C[4][3] = 9;
    C[6][3] = 5;
    
    C[4][8] = 2;
    C[8][4] = 2;
    
    C[5][7] = 5;
    C[5][8] = 1;
    
    C[7][5] = 5;
    C[8][5] = 1;
    
    C[6][7] = 4;
    C[7][6] = 4;
    
    
    /* Imprime matriz de costos */
    printf("Matriz de costos C\n\n");
    imprime(C);
    
    Floyd(C, A);
    
    /* Imprime matriz de distancias */
    printf("\n\nMatriz de distancias A\n\n");
    imprime(A);
    
}

void Floyd(int C[N][N], int A[N][N])
{
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            A[i][j]=C[i][j];    //copiar la matriz original en A
    
    for(int k = 0; k < N; ++k)
    {
        imprime(A);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
            {
                int temp = A[i][k] + A[k][j];
                if ( temp < A[i][j] )
                    A[i][j] = temp;
            }
    }
}

void imprime(int M[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            if (M[i][j] == 1000)
                printf("%3c", '-');
            else
                printf("%3d", M[i][j]);
        
        printf("\n");
    }
    
    printf("\n\n");
}

