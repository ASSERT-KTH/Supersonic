#include <stdio.h>
#define N 2

int matrix(double *x);

int main(void) {
  double x[(N + 1) * N];
  double *y[N];
  int i, j;
  char str[100];

  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]);
    
    for (i = 0; i < N; i++)
      y[i] = &x[i * (N + 1)];

    matrix(x);

    for (i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", y[i][N]);
    }
    printf("\n");
  }

  return 0;
}

int matrix(double *x) {
  int i, j, k;

  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      double su1 = x[k * (N + 1) + k];
      double su2 = x[j * (N + 1) + k];

      x[j * (N + 1)] = x[j * (N + 1)] - x[k * (N + 1)] * su2 / su1;
      x[j * (N + 1) + 1] = x[j * (N + 1) + 1] - x[k * (N + 1) + 1] * su2 / su1;
      x[j * (N + 1) + 2] = x[j * (N + 1) + 2] - x[k * (N + 1) + 2] * su2 / su1;
    }
  }

  for (k = 0; k < N - 1; k++) {
    for (j = k + 1; j < N; j++) {
      double su1 = x[(1 - k) * (N + 1) + (1 - k)];
      double su2 = x[(1 - j) * (N + 1) + (1 - k)];

      x[(1 - j) * (N + 1)] = x[(1 - j) * (N + 1)] - x[(1 - k) * (N + 1)] * su2 / su1;
      x[(1 - j) * (N + 1) + 1] = x[(1 - j) * (N + 1) + 1] - x[(1 - k) * (N + 1) + 1] * su2 / su1;
      x[(1 - j) * (N + 1) + 2] = x[(1 - j) * (N + 1) + 2] - x[(1 - k) * (N + 1) + 2] * su2 / su1;
    }
  }

  for (j = 0; j < N; j++) {
    double su1 = x[j * (N + 1) + j];

    x[j * (N + 1)] = x[j * (N + 1)] / su1;
    x[j * (N + 1) + 1] = x[j * (N + 1) + 1] / su1;
    x[j * (N + 1) + 2] = x[j * (N + 1) + 2] / su1;
  }

  return 0;
}