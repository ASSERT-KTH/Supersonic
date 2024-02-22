#include <cstdio>
#include <cstring>

int main() {
  int H, W;
  scanf("%d %d", &H, &W);
  char row1[W+2], row2[W+2];
  for (int i = 1; i <= W; i++) {
    row1[i] = ".#"[(i) & 1];
    row2[i] = ".#"[(i+1) & 1];
  }
  row1[W+1] = row2[W+1] = '\n';
  row1[W+2] = row2[W+2] = '\0';
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      printf("%s", ((i & 1) ? row1 : row2));
    }
    printf("\n");
    scanf("%d %d", &H, &W);
  }
  return 0;
}