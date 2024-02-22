#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int product = i * j; // Store the product in a variable to avoid redundant computation
      cout << i << "x" << j << "=" << product << "\n"; // Replace endl with \n to avoid unnecessary buffer flushes
    }
  }
  return 0;
}