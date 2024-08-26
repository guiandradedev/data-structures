#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} pt;

int main() {
    // alocacao estatica
    pt A;
    scanf("%d", &A.x);
    A,y = 0;

    // Alocacao dinamica
    pt *B;
    B = (pt*) malloc(1*sizeof(pt));
    return 0;
}