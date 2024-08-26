//
//  desafio2.c
//  Aula Pratica
//
//  Created by Guilherme Andrade on 14/08/24.
//

// Elabore um programa que leia um número inteiro e
// construa duas funções: uma que some os dígitos desse
// número inteiro e outra que determine o maior digito
// desse número. Exemplo: número = 1063, então a soma
// =1+ 0 +6 + 3 =10 e o maior dígito é 6

#include "stdio.h"

int is_perfect(int num) {
    int sum = 0, aux = 0, original = num;
    for(int i=1; i < num; i++) {
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
    
    printf(" a%d", is_perfect(num));
   
    return 1;
}

