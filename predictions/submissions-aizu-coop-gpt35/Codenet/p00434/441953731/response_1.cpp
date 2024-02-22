#include <iostream>
#include <bitset>
using namespace std;

int main() {
  bitset<31> data; // Using a bitset instead of a set

  for (int i = 0; i < 28; i++) {
    int n;
    cin >> n;
    data.set(n); // Setting the corresponding bit in the bitset
  }

  for (int i = 1; i <= 30; i++) { // Optimized loop range
    if (!data.test(i)) { // Checking if the bit is not set
      cout << i << endl;
    }
  }

  return 0;
}