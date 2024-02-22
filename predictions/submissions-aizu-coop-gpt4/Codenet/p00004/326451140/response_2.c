#include <stdio.h>
#define N 2
void matrix(double **x);

int main(void) {
  double x[N][N + 1];
  double *y[N] = {x[0], x[1]};
  int i;
  char str[100];
  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    matrix(y);
    printf("%3.3f %3.3f\n", x[0][N], x[1][N]);
  }
  return 0;
}

void matrix(double **x) {
  int i, j, k;
  double ratio;
  for (k = 0; k <= N - 2; k++) {
    for (j = k + 1; j <= N - 1; j++) {
      ratio = x[j][k] / x[k][k];
      for (i = 0; i <= 2; i++) {
        x[j][i] -= x[k][i] * ratio;
        x[1 - j][i] -= x[1 - k][i] * ratio;
      }
    }
  }
  for (j = 0; j <= N - 1; j++) {
    ratio = x[j][j];
    for (i = 0; i <= N; i++) {
      x[j][i] /= ratio;
    }
  }
}