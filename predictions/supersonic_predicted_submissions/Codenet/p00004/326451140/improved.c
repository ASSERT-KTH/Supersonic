#include <stdio.h>
#include <string.h>
#define N 2
int matrix(double **x);
int main(void) {
  double x[N][N + 1];
  double *y[N];
  double su1 = 0, su2 = 0;
  int i, j, k, n;
  char str[100], *line;
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N + 1; j++) {
        if (i == 0 && j == 0)
          line = strtok(str, " ");
        else
          line = strtok(NULL, " ");
        sscanf(line, "%d", &n);
        x[i][j] = n;
      }
    }
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
int matrix(double **x) {
  int i, j, k;
  double su1 = 0, su2 = 0;
  for (k = 0; k <= N - 2; k++) {
    for (j = k + 1; j <= N - 1; j++) {
      su1 = x[k][k];
      su2 = x[j][k];
      for (i = 0; i <= 2; i++) {
        x[j][i] = x[j][i] - x[k][i] * su2 / su1;
      }
    }
  }
  for (k = 0; k <= N - 2; k++) {
    for (j = k + 1; j <= N - 1; j++) {
      su1 = x[1 - k][1 - k];
      su2 = x[1 - j][1 - k];
      for (i = 0; i <= 2; i++) {
        x[1 - j][i] = x[1 - j][i] - x[1 - k][i] * su2 / su1;
      }
    }
  }
  su1 = 0;
  for (j = 0; j <= N - 1; j++) {
    su1 = x[j][j];
    for (i = 0; i <= N; i++) {
      x[j][i] = x[j][i] / su1;
    }
  }
  return 0;
}
