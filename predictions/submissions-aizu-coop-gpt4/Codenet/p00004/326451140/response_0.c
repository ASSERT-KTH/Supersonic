#include <stdio.h>
#define N 2
int matrix(double **x);
int main(void) {
  double x[N][N + 1];
  double *y[N];
  int i;
  char str[100];
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    for (i = 0; i < N; i++)
      y[i] = x[i];
    matrix(y);
    printf("%3.3f %3.3f\n", x[0][N], x[1][N]); // Removed unnecessary loop
  }
  return 0;
}
int matrix(double **x) {
  int i, j, k;
  double su1, su2;
  for (k = 0; k < N; k++) { // Outer loop
    su1 = x[k][k]; // Moved to outer loop
    for (j = k + 1; j < N; j++) { // Inner loop
      su2 = x[j][k]; // Moved to outer loop
      x[j][0] -= x[k][0] * su2 / su1;
      x[j][1] -= x[k][1] * su2 / su1;
      x[j][2] -= x[k][2] * su2 / su1; // Loop unrolling
    }
  }
  for (k = 0; k < N; k++) { // Outer loop
    su1 = x[1 - k][1 - k]; // Moved to outer loop
    for (j = k + 1; j < N; j++) { // Inner loop
      su2 = x[1 - j][1 - k]; // Moved to outer loop
      x[1 - j][0] -= x[1 - k][0] * su2 / su1;
      x[1 - j][1] -= x[1 - k][1] * su2 / su1;
      x[1 - j][2] -= x[1 - k][2] * su2 / su1; // Loop unrolling
    }
  }
  for (j = 0; j < N; j++) {
    su1 = x[j][j];
    x[j][0] /= su1;
    x[j][1] /= su1;
    x[j][2] /= su1; // Loop unrolling
  }
  return 0;
}