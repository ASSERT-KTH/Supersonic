#include <cstdio>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; i++) {
      string row = "";
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H) {
          row += "#";
        } else {
          if (j == 1 || j == W) {
            row += "#";
          } else {
            row += ".";
          }
        }
      }
      printf("%s\n", row.c_str());
    }
    printf("\n");
  }
}