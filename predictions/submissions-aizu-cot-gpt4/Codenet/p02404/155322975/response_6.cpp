#include <cstdio>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (1) {
    scanf("%d%d", &H, &W);
    if (H == 0 && W == 0)
      break;
    string first_last = string(W, '#') + "\n";
    string middle = "#" + string(W-2, '.') + "#\n";
    printf("%s", first_last.c_str());
    for (int i = 2; i < H; i++) {
      printf("%s", middle.c_str());
    }
    if (H > 1) {
      printf("%s", first_last.c_str());
    }
    printf("\n");
  }
  return 0;
}