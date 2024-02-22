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
  double su1 = 0, su2 = 0;
  double ratio, subtraction;
  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      ratio = su2 / su1;
      for (i = 0; i <= N; i++) {
        subtraction = x[k][i] * ratio;
        x[j][i] -= subtraction;
      }
    }
  }
  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      su1 = x[N - 1 - k][N - 1 - k];
      su2 = x[N - 1 - j][N - 1 - k];
      ratio = su2 / su1;
      for (i = 0; i <= N; i++) {
        subtraction = x[N - 1 - k][i] * ratio;
        x[N - 1 - j][i] -= subtraction;
      }
    }
  }
  for (j = 0; j < N; j++) {
    su1 = x[j][j];
    ratio = 1.0 / su1;
    for (i = 0; i <= N; i++) {
      x[j][i] *= ratio;
    }
  }
  return 0;
}