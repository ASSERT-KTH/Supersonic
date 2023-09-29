#include <stdio.h>
#include <stdlib.h>
#define N 2

void matrix(double x[N][N + 1]);

int main(void) {
  double x[N][N + 1];
  char str[100];

  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);

    matrix(x);

    for (int i = 0; i < N; i++) {
      printf("%3.3f ", x[i][N]);
    }
    printf("\n");
  }
  return 0;
}

void matrix(double x[N][N + 1]) {
  double su1, su2;

  for (int k = 0; k < N - 1; k++) {
    for (int j = k + 1; j < N; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      for (int i = k; i <= N; i++) {
        x[j][i] -= x[k][i] * su2 / su1;
      }
    }
  }

  for (int k = N - 1; k > 0; k--) {
    for (int j = k - 1; j >= 0; j--) {
      su1 = x[k][k];
      su2 = x[j][k];
      for (int i = N; i >= k; i--) {
        x[j][i] -= x[k][i] * su2 / su1;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    su1 = x[i][i];
    for (int j = 0; j <= N; j++) {
      x[i][j] /= su1;
    }
  }
}