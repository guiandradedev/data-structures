// Construa, em C, um programa que contenha as seguintes funções de
// Lista Encadeada- Básica
// • Inserção de um Elemento da Lista (pode ser o primeiro)
// • Remoção de um Elemento da Lista (pode ser o primeiro)
// • Impressão da Lista
// • Uma função que verifica se a lista está vazia, retorna 1 se ela estiver
// vazia e 0 caso contrário
// • Uma função que retorne a quantidade de elementos de uma lista. A
// lista é passada por parâmetro .
// • Uma função que some os elementos de uma lista que é passada por
// parâmetro
// • Uma função que receba duas listas e retorne uma terceira lista que é
// a união dessas duas listas (Não é permitido elementos repetidos na
// Lista União)

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} List;

List* inicialize() {
    return NULL;
}

List* insert(List *list, int value) {
    List *aux;
    aux = (List*)malloc(sizeof(List));
    aux->value=value;
    aux->next=list;
    return aux;
}

void print(List *list) {
    List *aux = list;
    while(aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->next;
    }
}

int is_empty(List *list) {
    return list == NULL;
}

int length(List *list) {
    int qt=0;
    while(list != NULL) {
        qt++;
        list = list->next;
    }
    return qt;
}

int sum_elements(List *list) {
    int sum=0;
    while(list != NULL) {
        sum += list->value;
        list = list->next;
    }
    return sum;
}

List* remove_first(List *list) {
    if(is_empty(list)) {
        return NULL;
    }
    List* aux = list;
    list=list->next;
    free(aux);
    return list;
}

List* liberate(List *list) {
    List* aux;
    while(list != NULL) {
        aux = list;
        list=list->next;
        free(aux);
    }
    return NULL;
}

int element_exists_in_list(List *list, int element) {
    int found = 0;
    while(list != NULL && found == 0) {
        if(element == list->value) {
            found = 1;
        }
        list = list->next;
    }
    return found;
}

List *union_two_lists(List *list1, List *list2) {
    List *aux;
    aux = inicialize();

    while(list1 != NULL) {
        if(!element_exists_in_list(aux, list1->value)) {
            aux = insert(aux, list1->value);
        }
        list1 = list1->next;
    }

    while(list2 != NULL) {
        if(!element_exists_in_list(aux, list2->value)) {
            aux = insert(aux, list2->value);
        }
        list2 = list2->next;
    }

    return aux;
}

int main() {
    List *start;
    start = inicialize();
    List *list2;
    list2 = inicialize();

    List *list_union;


    printf("Vazia: %d \n", is_empty(start));

    start = insert(start, 15);
    start = insert(start, 16);
    start = insert(start, 16);
    start = insert(start, 17);

    // printf("Valores inseridos!\n");

    // printf("Vazia: %d \n", is_empty(start));

    // printf("Qtd de elementos: %d\n", length(start));

    // print(start);

    // start = remove_first(start);
    // printf("Removido o ultimo\n");

    // printf("Qtd de elementos: %d\n", length(start));
    // print(start);

    // start = liberate(start);
    // printf("Qtd de elementos: %d\n", lengtb(start));
    // printf("Vazia: %d \n", is_empty(start));
    // print(start);

    list2 = insert(list2, 10);
    list2 = insert(list2, 15);
    list2 = insert(list2, 9);

    list_union=union_two_lists(start, list2);

    print(list_union);

    list = liberate(list);
    list2 = liberate(list2);

    return 0;
}