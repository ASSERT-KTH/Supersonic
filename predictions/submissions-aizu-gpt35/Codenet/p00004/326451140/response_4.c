#include <stdio.h>
#define N 2

void matrix(double x[N][N + 1]);

int main(void) {
  double x[N][N + 1];
  double su1 = 0;
  int i, j;
  char str[100];
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    matrix(x);
    for (i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", x[i][N]);
    }
    printf("\n");
  }
  return 0;
}

void matrix(double x[N][N + 1]) {
  double su1 = 0;
  int i, j, k;
  for (k = 0; k < N; k++) {
    // Pivotisation
    for (i = k + 1; i < N; i++) {
      if (x[k][k] < x[i][k]) {
        for (j = 0; j <= N; j++) {
          double temp = x[k][j];
          x[k][j] = x[i][j];
          x[i][j] = temp;
        }
      }
    }
    // Elimination
    for (i = k + 1; i < N; i++) {
      double t = x[i][k] / x[k][k];
      for (j = 0; j <= N; j++)
        x[i][j] = x[i][j] - t * x[k][j];
    }
  }
  // Back substitution
  for (i = N - 1; i >= 0; i--) {
    su1 = x[i][N];
    for (j = i + 1; j < N; j++) {
      su1 = su1 - x[i][j] * x[j][N];
    }
    x[i][N] = su1 / x[i][i];
  }
}