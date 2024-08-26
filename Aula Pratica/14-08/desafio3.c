//
//  desafio2.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

// Construa um programa que tenha uma função recursiva
// que tenha como parâmetro um número inteiro e
// determine quantos dígitos 5 possui esse número

#include "stdio.h"

int count_five(int num) {
    if(num == 0) return 0;

    if(num % 10 == 5) return 1 + count_five(num / 10);
    return count_five(num / 10);

}

int main(int argc, const char * argv[]) {
    int num;
    printf("Insira um numero inteiro\n");
    scanf("%d", &num);

    printf("O total eh %d", count_five(num));
       
    return 1;
}

