#include <iostream>
#include <bitset>
using namespace std;

int main() {
  bitset<31> data; // Use bitset instead of set
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n); // Set the bit corresponding to the number read
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i]) // If the bit corresponding to the number is not set
      cout << i << endl;
  }
}