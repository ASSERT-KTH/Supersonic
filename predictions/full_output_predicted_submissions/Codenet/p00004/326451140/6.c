#include <stdio.h>
#define N 2
int matrix(double **x);
int main(void) {
  double x[N][N + 1];
  double *y[N];
  double su1 = 0, su2 = 0;
  int i, j, k;
  char str[100];
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
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
      su1 += su