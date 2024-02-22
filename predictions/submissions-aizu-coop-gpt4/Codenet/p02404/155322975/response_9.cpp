#include <cstdio>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    string first_and_last_row = string(W, '#');
    string middle_row = "#" + string(W-2, '.') + "#";
    for (int i = 1; i <= H; i++) {
      if (i == 1 || i == H) {
        printf("%s\n", first_and_last_row.c_str());
      } else {
        printf("%s\n", middle_row.c_str());
      }
    }
    printf("\n");
  }
}