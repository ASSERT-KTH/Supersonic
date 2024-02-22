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
  for (k = 0; k < N; k++) {
    double su1 = x[k][k];
    for (j = k + 1; j < N; j++) {
      double su2 = x[j][k];
      for (i = k; i <= N; i++) {
        x[j][i] -= (x[k][i] * su2 / su1);
      }
    }
  }
  return 0;
}