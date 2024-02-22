#include <stdio.h>

int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;
  char buffer[400]; // Buffer to store the results
  scanf("%d %d", &row, &col);
  for (i = 0; i < row; i++) {
    ans[i] = 0; // Initialize ans[i] before it is used
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }
  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
    if (act[i] == 0) continue; // Skip if act[i] is 0
    for (j = 0; j < row; j++) {
      ans[j] += inact[j][i] * act[i];
    }
  }
  for (i = 0; i < row; i++) {
    int len = sprintf(buffer + strlen(buffer), "%d\n", ans[i]); // Append ans[i] to buffer
  }
  printf("%s", buffer); // Print the results in one go
  return 0;
}