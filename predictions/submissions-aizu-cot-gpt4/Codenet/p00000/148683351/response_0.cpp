#include <iostream>
using namespace std;
int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int product = i * j;
      cout << i << "x" << j << "=" << product << '\n';
    }
  }
  return 0;
}