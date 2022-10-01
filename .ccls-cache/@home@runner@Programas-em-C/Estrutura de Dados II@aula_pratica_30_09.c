#include <stdio.h>

typedef struct aluno {
  int mat; //matricula
  float media;
} Aluno;

int main(void) {
  Aluno j;
  j.mat = 10;
  j.media = 8.5;
  printf("Matricula %d, media %f.", j.mat, j.media);
  return 0;
}