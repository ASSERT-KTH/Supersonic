#include <iostream>

int main() {
  int H, W;
  scanf("%d %d", &H, &W);
  while (H != 0 && W != 0) {
    bool toggle = true;
    for (int i = 1; i <= H*W; i++) {
      printf("%c", ".#"[toggle]);
      toggle = !toggle;
      if (i % W == 0) {
        printf("\n");
        toggle = !toggle;
      }
    }
    printf("\n");
    scanf("%d %d", &H, &W);
  }
  return 0;
}