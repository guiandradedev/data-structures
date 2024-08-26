// Elabore um programa que crie uma estrutura com as
// seguintes informações de um produto:
// • Código do produto – inteiro de 3 dígitos
// • Quantidade em estoque - inteiro
// • Valor de compra - real
// • Valor de Venda - real
// • O programa deverá ler a informação de 10 produtos e
// determinar
// • O código do produto com maior quantidade de estoque
// • O quantidade de estoque do produto que proporciona o
// maior lucro

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int codigo, qtd;
    float compra, venda;
} Lista;

void ler_vetor(Lista *lista, int qtd) {
    for(int i=0; i<qtd; i++) {
        printf("----------\n");
        printf("Produto %d\n", i+1);
        printf("Insira o codigo\n");
        scanf("%d", &lista[i].codigo);

        printf("Insira o estoque\n");
        scanf("%d", &lista[i].qtd);

        printf("Insira o preco de compra\n");
        scanf("%f", &lista[i].compra);

        printf("Insira o preco de venda\n");
        scanf("%f", &lista[i].venda);
    }
}

void imprimir(Lista *lista, int qtd)  {
    for(int i=0; i<qtd; i++) {
        printf("----------\n");
        printf("Produto %d\n", lista[i].codigo);
        printf("Quantidade no estoque: %d\n", lista[i].qtd);
        printf("Preco de compra: %f\n", lista[i].compra);
        printf("Preco de venda: %f\n", lista[i].venda);
    }
}

int maior_estoque(Lista *lista, int qtd) {
    int maior = lista[0].qtd;
    int maior_codigo = 0;
    for(int i=1; i<qtd; i++) {
        if(lista[i].qtd > maior) {
            maior = lista[i].qtd;
            maior_codigo = lista[i].codigo;
        }
    }
    return maior_codigo;
}

int maior_lucro(Lista *lista, int qtd) {
    int maior = lista[0].venda - lista[0].compra;
    int estoque = 0;
    for(int i=1; i<qtd; i++) {
        if(lista[i].venda - lista[i].compra > maior) {
            maior = lista[i].venda - lista[i].compra;
            estoque = lista[i].qtd;
        }
    }
    return estoque;
}


int main() {
    int num=0;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &num);

    Lista *lista;
    lista = (Lista*)malloc(num*sizeof(Lista));

    ler_vetor(lista, num);

    imprimir(lista, num);

    printf("maior estoque: %d\n", maior_estoque(lista, num));
    printf("maior lucro: %d", maior_lucro(lista, num));


    free(lista);

    return 0;
}