//
//  desafio4.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

// Faça uma função recursiva que permita calcular a média
// um vetor de tamanho N

#include <stdio.h>

float media(int v[], int tam, int n) {
    if(tam == 0) return (float)v[n]/tam;
    return (float)v[n]/tam + media(v, tam, n-1);
}

int main(int argc, const char * argv[]) {
    int vetor[5] = {1,2,3,4,5};
    printf("%f", media(vetor,5, 4));
       
    return 0;
}

