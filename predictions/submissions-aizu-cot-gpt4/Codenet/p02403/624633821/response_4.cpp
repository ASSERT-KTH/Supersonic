#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a = 0, H[100], W[100];
  while (1) {
    cin >> H[a] >> W[a];
    if (H[a] == 0 && W[a] == 0)
      break;
      
    for (int i = 0; i < H[a]; i++) {
      for (int j = 0; j < W[a]; j++) {
        putchar('#');
      }
      putchar('\n');
    }
    putchar('\n');
    a++;
  }
  
  return 0;
}