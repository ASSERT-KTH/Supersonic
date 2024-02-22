#include <iostream>
using namespace std;

int main() {
  // Pre-calculate the multiplication table products
  int products[9][9];
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      products[i-1][j-1] = i * j;
    }
  }

  // Print the multiplication table
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << products[i-1][j-1] << '\n';
    }
  }

  return 0;
}