#include <stdio.h>
#define N 2
int matrix(double **x);
int main(void) {
  double x[N][N + 1];
  double *y[N];
  int i;
  char str[100];
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    for (i = 0; i < N; i++)
      y[i] = x[i];
    matrix(y);
    for (i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", x[i][N]);
    }
    printf("\n");
  }
  return 0;
}

#pragma GCC optimize("Ofast")
int matrix(double **x) {
  int i, j, k;
  double su1, su2, factor;
  for (k = 0; k < N - 1; k++) {
    su1 = x[k][k];
    for (j = k + 1; j < N; j++) {
      su2 = x[j][k];
      factor = su2 / su1;
      for (i = 0; i < N + 1; i++) {
        x[j][i] -= x[k][i] * factor;
      }
    }
  }
  for (k = N - 1; k > 0; k--) {
    su1 = x[k][k];
    for (j = k - 1; j >= 0; j--) {
      su2 = x[j][k];
      factor = su2 / su1;
      for (i = 0; i < N + 1; i++) {
        x[j][i] -= x[k][i] * factor;
      }
    }
  }
  for (j = 0; j < N; j++) {
    su1 = x[j][j];
    factor = 1.0 / su1;
    for (i = 0; i < N + 1; i++) {
      x[j][i] *= factor;
    }
  }
  return 0;
}