#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "pilha.h"

// Programa de teste da biblioteca Pilha

int main()
{
    Pilha *P=NULL;
    int num;
    char resp;
    setlocale(LC_ALL,"portuguese");

    P=CriaPilha();
    if(P==NULL)
    {
        printf("\n\n\t\t PILHA VAZIA!!!! A PILHA não foi criada!!!\n\n");
        exit(0);
    }
    system("cls");
    printf("\n\n\t==>INSERÇÃO dos Elementos na Pilha: <== \n");
    do
    {
        printf("\n\t\tDigite o elemento a ser inserido na pilha: ");
        scanf("%d",&num);
        push(P,num);
        printf("\n\t\t\t =>> Deseja inserir mais um número? (S/N)");
        fflush(stdin);
        resp=getchar();
    } while(toupper(resp)!='N');
    imprimePilha(P);
    num= pop(P);
    printf("\n\n\tElemento apagado da pilha: %d\n", num);
    printf("\n\n\tNova Pilha\n\t");
    imprimePilha(P);
    P=libera(P);
    /* Faça VOCÊ
        Uma função que:
        1- Conte os Elementos da Pilha
        2 - Inverta a Pilha
        3- Remova um determinado elemento da pilha, se existir
    */
}
