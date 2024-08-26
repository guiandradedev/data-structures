// A prefeitura de uma cidade fez uma pesquisa entre os
// seus habitantes, coletando dados sobre o salário, idade,
// sexo e número de filhos. Use a estrutura seguinte...
// struct dados{
// int idade, filhos;
// float salario;
// int sexo;
// }
// ...faça um programa que leia os dados de 100 habitantes e calcule:
// • A média de idade das mulheres com salário inferior ao salário
// mínimo.
// • A média de salário da população.
// • A média do número de filhos.
// • A menor idade do sexo feminino

#include <stdio.h>
#include <stdlib.h>

#define TOTAL 100
#define SALARIO_MINIMO 1300

typedef struct dados {
    int idade, filhos;
    float salario;
    char genero;
} Dados;

void ler_vetor(Dados *dados, int total) {
    for(int i=0; i<total; i++) {
        printf("Qual a sua idade?\n");
        scanf("%d", &dados[i].idade);

        printf("Quantos filhos vc tem?\n");
        scanf("%d", &dados[i].filhos);

        printf("Qual seu salario?\n");
        scanf("%f", dados[i].salario);

        printf("Qual seu genero? [H, M, O]\n");
        do {
            scanf("%c", dados[i].genero);
            if(dados[i].genero != "M" && dados[i].genero != "H" && dados[i].genero != "O") {
                printf("Voce precisa colocar um genero valido!\n");
            }
        } while(dados[i].genero != "M" && dados[i].genero != "H" && dados[i].genero != "O")
    }
}

float media_idade_salario(Dados *dados, int total, float salario) {
    float media = 0;
    int qtd = 0;
    for(int i=0; i<total; i++) {
        if(dados[i].genero == "M" && dados[i].salario <= salario) {
            media += dados[i].idade;
        }
    }
    return media / qtd;
}

float media_salario(Dados *dados, int total) {
    float media = 0;
    for(int i=0; i<total; i++) {
        media += dados[i].salario;
    }
    return media / total;
}

float media_filhos(Dados *dados, int total) {
    float media = 0;
    for(int i=0; i<total; i++) {
        media += dados[i].filhos;
    }
    return media / total;
}

int menor_idade(Dados *dados, int total) {
    int menor = dados[0].idade;
    for(int i=1; i<total; i++) {
        if(dados[i].idade < menor) {
            menor = dados[i].idade;
        }
    }
    return menor;
}

int main() {
    Dados dados[TOTAL];

    ler_vetor(dados, TOTAL);
    return 0;
}