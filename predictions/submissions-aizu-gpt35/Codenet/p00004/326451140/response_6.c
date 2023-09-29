#include <stdio.h>
#define N 2
void matrix(double x[N][N + 1]);
int main(void) {
  double x[N][N + 1];
  double su1 = 0, su2 = 0;
  int i, j;
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
void matrix(double x[N][N + 1]) {
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
}