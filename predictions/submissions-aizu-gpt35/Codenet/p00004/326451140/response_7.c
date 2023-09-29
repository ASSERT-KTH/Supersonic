#include <stdio.h>
#include <stdlib.h>
#define N 2
void matrix(double x[][N + 1]);
int main(void) {
  double x[N][N + 1];
  double su1 = 0;
  char str[100];
  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    matrix(x);
    for (int i = 0; i < N; i++) {
      if (i)
        printf(" ");
      printf("%3.3f", x[i][N]);
    }
    printf("\n");
  }
  return 0;
}
void matrix(double x[][N + 1]) {
  double su1 = 0;
  for (int k = 0; k < N-1; k++) {
    for (int j = k + 1; j < N; j++) {
      su1 = x[j][k] / x[k][k];
      for (int i = k; i <= N; i++) {
        x[j][i] -= x[k][i] * su1;
      }
    }
  }
  for (int i = N-1; i >= 0; i--) {
    for (int j = i + 1; j < N; j++) {
      x[i][N] -= x[i][j] * x[j][N];
    }
    x[i][N] /= x[i][i];
  }
}