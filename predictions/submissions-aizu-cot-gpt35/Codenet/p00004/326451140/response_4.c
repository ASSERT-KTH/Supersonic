#include <stdio.h>
#define N 2

void matrix(double x[N][N+1]);

int main(void) {
  double x[N][N+1];
  double *y[N];
  int i, j;
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

void matrix(double x[N][N+1]) {
  int i, j;

  for (j = 0; j < N; j++) {
    for (i = j+1; i < N; i++) {
      double su1 = x[j][j];
      double su2 = x[i][j];

      for (int k = 0; k <= N; k++) {
        x[i][k] -= x[j][k] * su2 / su1;
      }
    }
  }

  for (j = N - 1; j >= 0; j--) {
    double su1 = x[j][j];

    for (i = 0; i <= N; i++) {
      x[j][i] /= su1;
    }

    for (i = 0; i < j; i++) {
      double su2 = x[i][i];

      for (int k = 0; k <= N; k++) {
        x[i][k] -= x[j][k] * su2 / su1;
      }
    }
  }
}