#include <stdio.h>
#define N 2

void matrix(double (&x)[N][N + 1]);

int main(void) {
  double x[N][N + 1];
  int i;
  char str[100];

  while (fgets(str, sizeof(str), stdin) != NULL) {
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

void matrix(double (&x)[N][N + 1]) {
  int i, j, k;
  double ratio;

  for (k = 0; k < N; k++) {
    for (i = k+1; i < N; i++) {
      ratio = x[i][k] / x[k][k];
      for (j = 0; j <= N; j++) {
        x[i][j] -= ratio * x[k][j];
      }
    }
  }

  for (i = 0; i < N; i++) {
    ratio = x[i][i];
    for (j = 0; j <= N; j++) {
      x[i][j] /= ratio;
    }
  }
}