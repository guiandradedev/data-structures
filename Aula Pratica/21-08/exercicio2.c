// Faça um programa que realize a leitura dos seguintes dados
// relativos a um conjunto de alunos:
// • RA - inteiro
// • Código da Disciplina - inteiro de 4 dígitos
// • Nota1 e Nota 2 – valores reais que podem ser
// armazenados na forma de um vetor de 2 posições
// • Considere uma turma de até 10 alunos. Após ler todos os
// dados digitados, e depois de armazená-los em um vetor de
// estrutura, exibir na tela a listagem final dos alunos com as
// suas respectivas medias finais (use uma média ponderada:
// Nota1 com peso=1.0 e Nota2 com peso=2.0).

#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 3

typedef struct student {
    int ra, code;
    float notes[2];
} Student;

void read_students(Student *student, int total) {
    for(int i=0; i < total; i++) {
        printf("Aluno %d\n", i+1);

        printf("Qual o RA do aluno?\n");
        scanf("%d", &student[i].ra);

        printf("Qual o codigo da disciplina?\n");
        do
        {
            scanf("%d", &student[i].code);
            if(student[i].code < 999 || student[i].code > 9999) {
                printf("Voce precisa inserir um codigo de 4 digitos\n");
            }
        } while (student[i].code < 999 || student[i].code > 9999);

        printf("Qual a nota 1\n");
        do {
            scanf("%f", &student[i].notes[0]);
            if(student[i].notes[0] < 0 || student[i].notes[0] > 10) {
                printf("Voce precisa colocar uma nota entre 0 e 10!\n");
            }
        } while(student[i].notes[0] < 0 || student[i].notes[0] > 10);
        printf("Qual a nota 2\n");
        do {
            scanf("%f", &student[i].notes[1]);
            if(student[i].notes[1] < 0 || student[i].notes[1] > 10) {
                printf("Voce precisa colocar uma nota entre 0 e 10!\n");
            }
        } while(student[i].notes[1] < 0 || student[i].notes[1] > 10);
        printf("----------\n");
    }
}

void media(Student *students, int total) {
    printf("Media dos alunos:\n");
    float aux = 0;
    for(int i=0; i<total; i++) {
        printf("Aluno %d na disciplina %d\n", students[i].ra, students[i].code);
        aux = (students[i].notes[0] + 2*students[i].notes[1])/3;
        printf("Media: %.2f\n", aux);
    }
}

int main() {
    Student student[NUM_STUDENTS];
    read_students(student, NUM_STUDENTS);
    media(student, NUM_STUDENTS);
    return 0;
}