#include <cstdio>
#include <string>

int main() {
  int H, W;
  
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0) {
      break;
    }

    // Compute the border and middle strings once
    std::string border(W, '#');
    std::string middle = "#" + std::string(W-2, '.') + "#";

    // Print the first row
    printf("%s\n", border.c_str());

    // Print the H-2 middle rows
    for (int i = 1; i < H-1; i++) {
      printf("%s\n", middle.c_str());
    }

    // Print the last row
    if (H > 1) {
      printf("%s\n", border.c_str());
    }

    printf("\n");
  }

  return 0;
}