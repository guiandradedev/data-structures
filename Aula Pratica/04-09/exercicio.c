#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"
#include "PILHA.h"

int conta_par(Fila *fila) {
    int qtd = 0;
    No *aux = fila->ini;
    while(aux != NULL) {
        if(aux->info % 2 == 0) {
            qtd ++;
        }
        aux = aux->prox;
    }
    return qtd;
}

void tira_15(Fila *fila) {
    int v;
    Fila *aux = CriaFila();
    while(!VaziaFila(fila)) {
        v = RetiraFila(fila);
        if(v != 15) {
            InsereFila(aux, v);
        }
    }

    fila->ini = aux->ini;
    fila->fim = aux->fim;
    free(aux);    
}
// Fila* tira_15(Fila *fila) {
//     int v;
//     Fila *aux = CriaFila();
//     while(!VaziaFila(fila)) {
//         v = RetiraFila(fila);
//         if(v != 15) {
//             InsereFila(aux, v);
//         }
//     }
//     return aux;
// }

void separa_fila(Fila *original, Fila *f1, Fila *f2) {
    No *aux = original->ini;
    while(aux != NULL) {
        if(aux->info % 2 == 0) {
            InsereFila(f1, aux->info);
        } else {
            InsereFila(f2, aux->info);
        }
        aux = aux->prox;
    }
}

void inverter_fila(Fila *fila) {
    Pilha *aux = CriaPilha();
    while(!VaziaFila(fila)) {
        push(aux, RetiraFila(fila));
    }
    while(!vaziaPilha(aux)) {
        InsereFila(fila, pop(aux));
    }
    aux = libera(aux);
}

void transformar_fila(Fila *fila, Pilha *p1, Pilha *p2) {
    No *aux = fila->ini;
    while(aux != NULL) {
        if(aux->info > 20) {
            push(p1, aux->info);
        } else {
            push(p2, aux->info);
        }
        aux = aux->prox;
    }
}

int main() {
    Fila *f1 = CriaFila();
    InsereFila(f1, 2);
    InsereFila(f1, 5);
    InsereFila(f1, 6);
    InsereFila(f1, 15);
    InsereFila(f1, 10);
    InsereFila(f1, 25);
    InsereFila(f1, 22);
    InsereFila(f1, 27);
    InsereFila(f1, 15);
    InsereFila(f1, 28);
    InsereFila(f1, 12);


    printf("Quantidade de pares: %d\n", conta_par(f1));

    imprimeFila(f1);
    printf("15 removido!\n");
    tira_15(f1);
    imprimeFila(f1);

    printf("Separando as filas:\n");
    Fila *f2 = CriaFila();
    Fila *f3 = CriaFila();
    separa_fila(f1, f2, f3);
    printf("Fila 2: ");
    imprimeFila(f2);
    printf("Fila 3: ");
    imprimeFila(f3);

    printf("Inverter fila 1:");
    inverter_fila(f1);
    imprimeFila(f1);

    printf("Separar maiores que 20 e menores que 20\n");
    Pilha *p1 = CriaPilha();
    Pilha *p2 = CriaPilha();
    transformar_fila(f1, p1, p2);
    printf("Pilha 1:");
    imprimePilha(p1);
    printf("Pilha 2:");
    imprimePilha(p2);

    f1 = liberaFila(f1);
    f2 = liberaFila(f2);
    f3 = liberaFila(f3);

    p1 = libera(p1);
    p2 = libera(p2);
    return 0;
}