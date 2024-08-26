#include <stdio.h>

struct ponto {
    int x, y;
}
typedef struct ponto pt;

/**
 * Os codigos acima e os abaixo representam a mesma coisa
 * a diferença é que o código debaixo é reduzido
 */

typedef struct ponto2 {
    int x, y;
} pt2;

int main() {
    return 0;
}