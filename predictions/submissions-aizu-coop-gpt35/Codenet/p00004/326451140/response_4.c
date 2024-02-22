#include <stdio.h>

#define N 2
#define M (N + 1)

void matrix(double *x[N]);
void print_result(double *x[N]);

int main(void) {
  double x[N][M];
  char str[100];

  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);

    matrix((double**) x);
    print_result((double**) x);
  }

  return 0;
}

void matrix(double *x[N]) {
  int i, j, k;
  double su1 = 0, su2 = 0;

  for (k = 0; k < N; k++) {
    for (j = k + 1; j < N; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      for (i = 0; i < M; i++) {
        x[j][i] = x[j][i] - x[k][i] * su2 / su1;
      }
    }
  }

  su1 = 0;
  for (j = 0; j < N; j++) {
    su1 = x[j][j];
    for (i = 0; i < M; i++) {
      x[j][i] = x[j][i] / su1;
    }
  }
}

void print_result(double *x[N]) {
  int i, j;

  for (i = 0; i < N; i++) {
    if (i)
      printf(" ");
    printf("%3.3f", x[i][N]);
  }

  printf("\n");
}