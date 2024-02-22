#include <iostream>
#include <bitset>
using namespace std;

int main() {
  bitset<31> data; // Use a bitset instead of a set

  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n); // Set the bit corresponding to the input number
  }

  for (int i = 1; i <= 30; i++) {
    if (!data.test(i)) // Check if the bit is not set
      cout << i << endl;
  }
}