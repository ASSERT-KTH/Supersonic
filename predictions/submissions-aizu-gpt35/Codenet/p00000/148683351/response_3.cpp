#include <iostream>
using namespace std;
int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
        int res = i * j;
        printf("%dx%d=%d\n", i, j, res);
    }
  }
  return 0;
}