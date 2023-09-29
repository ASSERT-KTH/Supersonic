#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  int a = 0, b = 0, H[100], W[100];
  while (1) {
    cin >> H[a] >> W[A];
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  while (b < a) {
    for (int i = 0; i < H[b]; i++) {
      for (int j = 0; j < W[b]; j++) {
        printf("#");
      }
      printf("\n");
    }
    b++;
    printf("\n");
  }
  return 0;
}
