#include <stdio.h>
#define N 2
int matrix(double **x);
int main(void) {
  double x[N][N + 1];
  double *y[N];
  char str[100];
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    for (int i = 0; i < N; i++)
      y[i] = x[i];
    matrix(y);
    for (int i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", x[i][N]);
    }
    printf("\n");
  }
  return 0;
}
int matrix(double **x) {
  double su1, su2;
  for (int k = 0; k <= N - 2; k++) {
    int inv_k = 1 - k;
    for (int j = k + 1; j <= N - 1; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      double factor = su2 / su1;
      for (int i = 0; i <= 2; i++) {
        x[j][i] -= x[k][i] * factor;
      }
    }
    for (int j = k + 1; j <= N - 1; j++) {
      int inv_j = 1 - j;
      su1 = x[inv_k][inv_k];
      su2 = x[inv_j][inv_k];
      double factor = su2 / su1;
      for (int i = 0; i <= 2; i++) {
        x[inv_j][i] -= x[inv_k][i] * factor;
      }
    }
  }
  for (int j = 0; j <= N - 1; j++) {
    su1 = x[j][j];
    double inv_su1 = 1.0 / su1;
    for (int i = 0; i <= N; i++) {
      x[j][i] *= inv_su1;
    }
  }
  return 0;
}