#include <stdio.h>
#include <string>
using namespace std;

int main() {
  int h, w;
  while (scanf("%d%d", &h, &w) == 2 && h != 0 && w != 0) {
    string row(w, '#');
    for (int i = 0; i < h; i++) {
      printf("%s\n", row.c_str());
    }
    printf("\n");
  }
  return 0;
}