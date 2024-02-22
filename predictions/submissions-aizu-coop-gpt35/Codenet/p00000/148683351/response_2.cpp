#include <iostream>
using namespace std;

int main() {
  // Use a matrix to store the multiplication results
  int results[10][10];

  // Calculate and store the results
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      results[i][j] = i * j;
    }
  }

  // Print the results
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << results[i][j] << " ";
    }
    cout << endl; // Moved outside the inner loop
  }

  return 0;
}