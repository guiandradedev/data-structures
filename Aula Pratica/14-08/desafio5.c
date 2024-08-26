//
//  desafio4.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

// Escreva uma função recursiva que retorne o menor
// elemento em um vetor

#include "stdio.h"

int menor(int v[], int tam) {
    if(tam == 0) {
        return 999;
    }
    return v[tam - 1] < menor(v, tam-1) ? v[tam-1] : 0;
}

int main(int argc, const char * argv[]) {
    int vetor[5] = {1,2,3,4,5};
    printf("%d", menor(vetor,5));
       
    return 0;
}

