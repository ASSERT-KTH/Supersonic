#include <stdio.h>

#define N 2

void matrix(double x[][N + 1]);

int main(void) {
  double x[N][N + 1];
  char str[100];

  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);

    matrix(x);

    printf("%3.3f %3.3f\n", x[0][N], x[1][N]);
  }

  return 0;
}

void matrix(double x[][N + 1]) {
  int i, j;

  for (j = 0; j <= N - 1; j++) {
    double su1 = x[j][j];

    for (i = 0; i <= N; i++) {
      x[j][i] /= su1;
    }

    for (i = j + 1; i <= N - 1; i++) {
      double su2 = x[i][j];

      for (int k = 0; k <= N; k++) {
        x[i][k] -= x[j][k] * su2;
      }
    }
  }
}