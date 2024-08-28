/**
 * Pilhas
 * 
 * Crie um procedimento que inverta uma pilha
 * Crie um procedimento que conte quantos numeros pares uma pilha possui e retorne esta quantidade
 * Crie um procedimento que apague a informacao 15 da pilha caso exista
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct stack {
    struct node *topo;
} Stack;

// Node functions
Node* insert(Node *node, int value);
Node* remove_last(Node *node);

// Stack functions
Stack* create();
void push(Stack *stack, int value);
int pop(Stack *stack);
int is_empty(Stack *stack);
void print_stack(Stack *stack);
int length(Stack *stack);
Stack* free_stack(Stack *stack);

// Assignment functions
Stack* invert(Stack *stack);
int count_even(Stack *stack);
int count_odd(Stack *stack);
int remove_index(Stack *stack, int index);
int remove_element(Stack *stack, int element);

int compare(Stack *stack1, Stack *stack2);
Stack *read_number(int num);
void print_number(Stack *stack);


int main() {
    Stack *stack = create();

    printf("ta vazio? %d\n", is_empty(stack));
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);

    // print_stack(stack);
    // remove_element(stack, 7);
    // printf("---");
    // print_stack(stack);

    // // printf("Quantidade de numeros pares: %d\n", count_even(stack));
    // // printf("Quantidade de numeros impares: %d\n", count_odd(stack));
    // // printf("ta vazio? %d\n", is_empty(stack));

    // // // Remover elemento
    // // int v = pop(stack);
    // // printf("valor removido: %d\n", v);
    // // print_stack(stack);

    // // // Inverter Pilha
    // // print_stack(stack);
    // // printf("---");
    // // stack = invert(stack);
    // // print_stack(stack);

    // // Remover elemento
    // print_stack(stack);
    // printf("---\n");
    // int removed = remove_index(stack, 5); // removi o elemento 7
    // printf("Remover elemento\n");
    // // print_stack(stack);
    // // printf("Elemento removido: %d\n", removed);

    // // // Ler um numero e converte-lo pra stack, depois imprimi-lo
    // // Stack* num = read_number(5794);
    // // print_number(num);

    stack = free_stack(stack);
    if(stack == NULL) {
        printf("Pilha vazia\n");
    }
    return 0;
}

Node* insert(Node *node, int value) {
    Node *aux = (Node*)malloc(sizeof(Node));
    aux->value = value;
    aux->next = node;
    return aux;
}

Node* remove_last(Node *node){
    // if(is_empty(list)) {
    //     return NULL;
    // }
    Node* aux = node;
    node=node->next;
    free(aux);
    return node;
}

Stack* create() {
    Stack* stack ;
    stack=(Stack*)malloc(sizeof(Stack));
    stack->topo = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    stack->topo = insert(stack->topo, value);
}

int pop(Stack *stack) {
    // if(is_empty(list)) {
    //     return NULL;
    // }
    int aux = stack->topo->value;
    stack->topo = remove_last(stack->topo);
    return aux;
}

void print_stack(Stack *stack) {
    Node *aux = stack->topo;
    while(aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->next;
    }
}

int is_empty(Stack *stack) {
    return stack->topo == NULL;
}

int length(Stack *stack) {
    Node *aux = stack->topo;
    int count = 0;
    while(aux != NULL) {
        count++;
        aux = aux->next;
    }
    return count;
}

int count_even(Stack *stack){
    Node *aux = stack->topo;
    int count = 0;

    while(aux != NULL) {
        if(aux->value % 2 == 0) {
            // if parity condition is odd, system will validate if the number is odd
            count++;
        }
        aux = aux->next;
    }
    return count;
}
int count_odd(Stack *stack){
    Node *aux = stack->topo;
    int count = 0;

    while(aux != NULL) {
        if(aux->value % 2 != 0) {
            // if parity condition is odd, system will validate if the number is odd
            count++;
        }
        aux = aux->next;
    }
    return count;
}

int remove_element(Stack *stack, int element) {
    Stack *aux = create();
    int found = 0, counter=0;
    while(stack->topo != NULL && found == 0) {
        if(stack->topo->value == element) {
            found = 1;
            pop(stack);
            // break;
        } else {
            push(aux, pop(stack));
            counter++;
        }
    }
    for(int i=0; i<counter; i++) {
        push(stack, pop(aux));
    }
    return found;
}

int remove_index(Stack *stack, int index) {
    if(length(stack) < index) {
        printf("Valor inválido!");
        exit(1);
    }
    Stack *aux= create();
    int count = 0;
    int removed = 0;
    for(int i=0; i<index - 1; i++) {
        // vai ate o elemento anterior e insere na pilha auxiliar
        push(aux, pop(stack));
    }
    removed = pop(stack); // removo o elemento
    for(int i=0; i<index - 1; i++) {
        push(stack, pop(aux));
    }
    return removed;
    
}

Stack* invert(Stack *stack) {
    Stack *aux = create();

    while(stack->topo != NULL) {
        push(aux, pop(stack));
    }
    free(stack);
    return aux;
}

int compare(Stack *stack1, Stack *stack2) {
    int length1 = length(stack1);
    int length2 = length(stack2);

    if(length1 > length2) {
        return 1;
    }
    if(length1 < length2) {
        return 2;
    }
    return 0;
}

Stack *read_number(int num) {
    Stack *stack = create();
    while(num != 0) {
        push(stack, num % 10);
        num /= 10;
    }
    return stack;
}

void print_number(Stack *stack) {
    Stack* aux = stack;
    while(aux->topo != NULL) {
        printf("%d", pop(aux));
    }
    printf("\n");
}

Stack* free_stack(Stack *stack) {
    Node *node = stack->topo;
    while(node != NULL) {
        Node *aux = node->next;
        free(node);
        node = aux;
    }
    free(stack);
    return NULL;
}