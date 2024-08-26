#include <stdio.h>
#include <stdlib.h>

/**
 * Objetivos da alocaçào dinamica>
 * - Deixar para o programador decidir quando o programa vai alocar memoria e quanto vai alocar
 * isso eh bem util principalmente para declarar vetores
 * 
 * Formato errado:
 * int n;
 * // le n
 * int v[n]
 * 
 * Isso esta errado visto que caso altere o valor de N, vai afetar o tamanho do vetor, quebrando o codigo.
 */

int main() {
    int n, *v;
    scanf("%d", &n);

    v = (int*) malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        v[i] = i*i;
    }

    for(int i=0; i<n;i++) {
        printf(" %d ", v[i]);
    }

    free(v);
    return 0;
}