#include <cstdio>
int main() {
  int H, W;
  while (scanf("%d %d", &H, &W), H || W) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        putchar(".#"[i % 2 == j % 2]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}
