#include <stdio.h>

int main() {
  int inact[100][100];
  int act[100];
  int row, i, j;

  scanf("%d", &row);

  for (i = 0; i < row; i++) {
    for (j = 0; j < row; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (i = 0; i < row; i++) {
    scanf("%d", &act[i]);
  }

  for (i = 0; i < row; i++) {
    int ans = 0;
    for (j = 0; j < row; j++) {
      ans += inact[i][j] * act[j];
    }
    printf("%d\n", ans);
  }

  return 0;
}