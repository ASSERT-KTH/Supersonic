#include <stdio.h>

int main() {
  int H, W;
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    
    for (int i = 0; i < H; i++) {
      printf("%.*s\n", W, "##################################################");
    }
    printf("\n");
  }
  return 0;
}