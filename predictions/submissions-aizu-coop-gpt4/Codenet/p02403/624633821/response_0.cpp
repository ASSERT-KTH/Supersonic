#include <stdio.h>
#include <string>
using namespace std;

int main() {
  int a = 0, H[100], W[100];
  while (1) {
    scanf("%d %d", &H[a], &W[a]);
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  for (int b = 0; b < a; b++) {
    string row(W[b], '#');
    for (int i = 0; i < H[b]; i++) {
      printf("%s\n", row.c_str());
    }
    printf("\n");
  }
  return 0;
}