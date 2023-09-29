#include <stdio.h>
#define N 2

void matrix(double x[N][N + 1]) {
  double su1, su2;
  int i, j, k;

  for (k = 0; k < N - 1; k++) {
    su1 = x[k][k];
    for (j = k + 1; j < N; j++) {
      su2 = x[j][k];
      for (i = 0; i <= N; i++) {
        x[j][i] -= x[k][i] * su2 / su1;
      }
    }
  }

  for (k = N - 1; k > 0; k--) {
    su1 = x[k][k];
    for (j = k - 1; j >= 0; j--) {
      su2 = x[j][k];
      for (i = 0; i <= N; i++) {
        x[j][i] -= x[k][i] * su2 / su1;
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

int main(void) {
  double x[N][N + 1];
  int i;

  while(scanf("%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]) == 6) {
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