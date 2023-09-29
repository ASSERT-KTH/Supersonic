#include <stdio.h>
#define N 2
void matrix(double (*x)[N + 1]);
int main(void) {
  double x[N][N + 1];
  int i;
  char str[100];
  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    matrix(x);
    for (i = 0; i < N; i++) {
      printf((i ? " %3.3f" : "%3.3f"), x[i][N]);
    }
    printf("\n");
  }
  return 0;
}
void matrix(double (*x)[N + 1]) {
  int i, j, k;
  double su1, su2;
  for (k = 0; k <= N - 2; k++) {
    su1 = x[k][k];
    for (j = k + 1; j <= N - 1; j++) {
      su2 = x[j][k] / su1;
      for (i = 0; i <= N; i++) {
        x[j][i] -= x[k][i] * su2;
      }
    }
  }
  for (k = N - 2; k >= 0; k--) {
    su1 = x[k + 1][k + 1];
    for (j = k; j >= 0; j--) {
      su2 = x[j][k + 1] / su1;
      for (i = 0; i <= N; i++) {
        x[j][i] -= x[k + 1][i] * su2;
      }
    }
  }
  for (j = 0; j < N; j++) {
    su1 = x[j][j];
    for (i = 0; i <= N; i++) {
      x[j][i] /= su1;
    }
  }
}