#include <stdio.h>
#define N 2
int matrix(double x[N][N + 1]);
int main(void) {
  double x[N][N + 1];
  int i;
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
int matrix(double x[N][N + 1]) {
  int i, j, k;
  double su1, su2, su1_reciprocal;
  for (k = 0; k <= N - 2; k++) {
    for (j = k + 1; j <= N - 1; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      su1_reciprocal = 1.0 / su1;
      for (i = 0; i <= 2; i++) {
        if (k == 0) {
          x[j][i] -= x[k][i] * su2 * su1_reciprocal;
        } else {
          x[1 - j][i] -= x[1 - k][i] * (x[1 - j][1 - k] / x[1 - k][1 - k]);
        }
      }
    }
  }
  for (j = 0; j <= N - 1; j++) {
    su1 = x[j][j];
    su1_reciprocal = 1.0 / su1;
    for (i = 0; i <= N; i++) {
      x[j][i] *= su1_reciprocal;
    }
  }
  return 0;
}