#include <stdio.h>
#define N 2

void matrix(double *x);

int main(void) {
  double x[(N + 1) * N];
  double *y[N];
  int i, j;
  char str[100];

  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0], &x[1], &x[2],
           &x[N + 1], &x[N + 2], &x[2 * (N + 1)]);
    
    for (i = 0; i < N; i++)
      y[i] = &x[i * (N + 1)];

    matrix(x);

    for (i = 0; i < N - 1; i++) {
      printf("%3.3f ", y[i][N]);
    }
    printf("%3.3f\n", y[N - 1][N]);
  }

  return 0;
}

void matrix(double *x) {
  int i, j, k;
  double su1, su2;

  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      su1 = x[k * (N + 1) + k];
      su2 = x[j * (N + 1) + k];

      for (i = 0; i <= N; i++) {
        x[j * (N + 1) + i] -= (x[k * (N + 1) + i] * su2 / su1);
      }
    }
  }

  su1 = 0;

  for (j = 0; j < N; j++) {
    su1 = x[j * (N + 1) + j];

    for (i = 0; i <= N; i++) {
      x[j * (N + 1) + i] /= su1;
    }
  }
}