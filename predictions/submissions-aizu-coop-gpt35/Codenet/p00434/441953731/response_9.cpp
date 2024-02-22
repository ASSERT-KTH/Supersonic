#include <iostream>
using namespace std;

int main() {
  // Disable synchronization between C and C++ I/O streams
  ios_base::sync_with_stdio(false);

  // Create an array to store the occurrence of each number
  bool present[31] = {false};

  // Read the numbers and mark their occurrence in the array
  for (int i = 0; i < 28; i++) {
    int n;
    cin >> n;
    present[n] = true;
  }

  // Print the numbers that are not present
  for (int i = 1; i <= 30; i++) {
    if (!present[i]) {
      cout << i << '\n';
    }
  }

  return 0;
}