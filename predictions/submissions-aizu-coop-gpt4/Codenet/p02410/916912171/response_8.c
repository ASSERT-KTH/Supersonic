#include <stdio.h>
#include <string.h>

int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;

  // Use memset to initialize the arrays 'act' and 'ans' to 0
  memset(act, 0, sizeof(act));
  memset(ans, 0, sizeof(ans));

  scanf("%d %d", &row, &col);

  // Initialize only the required cells of the 'inact' array
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      inact[i][j] = 0;
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (int i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }

  for (int i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}