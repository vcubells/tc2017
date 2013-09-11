//  Algoritmo de Floyd-Warshall
//  main.c
//  t4c6e1
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 15

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
    
    C[0][2] = 4;
    C[0][4] = 4;
    
    C[1][3] = 8;
    C[1][9] = 1;
    
    C[2][1] = 9;
    C[2][4] = 5;
    C[2][11] = 5;
    
    C[3][4] = 6;
    C[3][5] = 6;
    C[3][6] = 4;
    C[3][13] = 8;
    
    C[4][7] = 9;
    C[4][3] = 8;
    
    C[5][6] = 3;
    
    C[6][8] = 8;
    C[6][7] = 2;
    
    C[7][14] = 7;
    
    C[8][6] = 7;
    C[8][9] = 16;
    C[8][12] = 3;
    
    C[9][8] = 7;
    
    C[10][12] = 3;
    
    C[11][2] = 9;
    
    C[12][8] = 5;
    C[12][10] = 10;
    C[12][13] = 7;
    
    C[13][3] = 8;
    
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
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
            {
                int temp = A[i][k] + A[k][j];
                if ( temp < A[i][j] )
                    A[i][j] = temp;
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
}

