//
//  desafio4.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

#include <stdio.h>

float media(int v[], int n) {
    if(n == 1) return *v;
    return ((media(v, n-1)*(n-1) + (*(v+n-1)))/n);
}

int main(int argc, const char * argv[]) {
    int vetor[5] = {1,2,3,4,5};
    printf("%f", media(vetor,5));
       
    return 0;
}

