#include <stdio.h>

#define N 2

void matrix(double x[][N+1]);

int main(void) {
  double x[N][N + 1];
  char str[100];
  
  for (; fgets(str, sizeof(str), stdin) != NULL;) {
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

void matrix(double x[][N+1]) {
  for (int k = 0; k <= N - 2; k++) {
    for (int j = k + 1; j <= N - 1; j++) {
      double su1 = x[k][k];
      double su2 = x[j][k];
      for (int i = 0; i <= N; i++) {
        x[j][i] = x[j][i] - x[k][i] * su2 / su1;
      }
    }
  }
  
  double su1 = 0;
  for (int j = 0; j <= N - 1; j++) {
    su1 = x[j][j];
    for (int i = 0; i <= N; i++) {
      x[j][i] = x[j][i] / su1;
    }
  }
}