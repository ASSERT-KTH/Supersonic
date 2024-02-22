#include <stdio.h>
#define N 2

int matrix(double *x);

int main(void) {
  double x[(N + 1) * N];
  double *y = x;
  double su1 = 0, su2 = 0;
  int i, j, k;
  char str[100];

  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0], &x[1], &x[2],
           &x[N + 1], &x[N + 2], &x[2 * N + 2]);
    matrix(y);
    for (i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", x[i * (N + 1) + N]);
    }
    printf("\n");
  }
  return 0;
}

int matrix(double *x) {
  int i, j, k;
  double su1 = 0, su2 = 0;
  for (k = 0; k <= N - 2; k++) {
    for (j = k + 1; j <= N - 1 || j == 1 - k; j++) {
      su1 = x[k * (N + 1) + k];
      su2 = x[j * (N + 1) + k];
      for (i = 0; i <= N; i++) {
        x[j * (N + 1) + i] = x[j * (N + 1) + i] - x[k * (N + 1) + i] * su2 / su1;
      }
    }
  }
  su1 = 0;
  for (j = 0; j <= N - 1; j++) {
    su1 = x[j * (N + 1) + j];
    for (i = 0; i <= N; i++) {
      x[j * (N + 1) + i] = x[j * (N + 1) + i] / su1;
    }
  }
  return 0;
}