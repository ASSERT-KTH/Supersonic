#include <stdio.h>

#define N 2

void matrix(double x[N][N + 1]);

int main(void) {
  double x[N][N + 1];
  char str[100];
  
  while (fgets(str, sizeof(str), stdin) != NULL) {
    sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2],
           &x[1][0], &x[1][1], &x[1][2]);
    
    matrix(x);
    
    for (int i = 0; i < N; i++) {
      if (i > 0)
        printf(" ");
      printf("%3.3f", x[i][N]);
    }
    printf("\n");
  }
  
  return 0;
}

void matrix(double x[N][N + 1]) {
  double su1, su2;
  
  for (int k = 0; k < N; k++) {
    su1 = x[k][k];
    
    for (int j = k + 1; j < N; j++) {
      su2 = x[j][k];
      
      for (int i = 0; i <= N; i++) {
        x[j][i] = x[j][i] - x[k][i] * su2 / su1;
      }
    }
  }
  
  su1 = x[N - 1][N - 1];
  
  for (int j = N - 2; j >= 0; j--) {
    su2 = x[j][N - 1];
    
    for (int i = 0; i < N; i++) {
      x[j][i] = x[j][i] - x[N - 1][i] * su2 / su1;
    }
  }
  
  for (int j = 0; j < N; j++) {
    su1 = x[j][j];
    
    for (int i = 0; i < N; i++) {
      x[j][i] = x[j][i] / su1;
    }
  }
}