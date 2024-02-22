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
int matrix(double **x) {
  int i, j, k;
  double su;
  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      su = x[k][k];
      for (i = 0; i < N+1; i++) {
        x[j][i] = x[j][i] - x[k][i] * x[j][k] / su;
      }
    }
  }
  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      su = x[1 - k][1 - k];
      for (i = 0; i < N+1; i++) {
        x[1 - j][i] = x[1 - j][i] - x[1 - k][i] * x[1 - j][1 - k] / su;
      }
    }
  }
  for (j = 0; j < N; j++) {
    su = x[j][j];
    for (i = 0; i < N+1; i++) {
      x[j][i] = x[j][i] / su;
    }
  }
  return 0;
}