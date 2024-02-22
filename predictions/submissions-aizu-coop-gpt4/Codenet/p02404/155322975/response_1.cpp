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
      string line = "";
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H) {
          line += "#";
        } else {
          if (j == 1 || j == W) {
            line += "#";
          } else {
            line += ".";
          }
        }
      }
      printf("%s\n", line.c_str());
    }
    printf("\n");
  }
}