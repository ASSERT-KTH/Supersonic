#include <algorithm>
#include <cstdio>
#include <string>

int main() {
  int a = 0, b = 0, H[100], W[100];
  while (1) {
    scanf("%d %d", &H[a], &W[a]);
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  while (b < a) {
    int curH = H[b], curW = W[b];
    std::string line(curW, '#');
    for (int i = 0; i < curH; i++) {
      printf("%s\n", line.c_str());
    }
    b++;
    printf("\n");
  }
  return 0;
}