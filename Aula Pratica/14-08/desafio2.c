//
//  desafio2.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

// Um número é perfeito se a soma dos seus divisores, com
// exceção dele mesmo, é igual a ele. Exemplo: número 6,
// os divisores de 6 são 1, 2, 3 e 6. Somando-se 1 + 2 + 3 =6.
// Portanto 6 é um número perfeito. Elabore um programa
// que leia um número e usando uma função determine se
// ele é perfeito

#include "stdio.h"

int is_perfect(int num) {
    int sum = 0;
    for(int i=1; i <= num / 2; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    int num;
    printf("Insira um numero inteiro\n");
    scanf("%d", &num);
    
    printf("%d", is_perfect(num));
   
    return 1;
}

