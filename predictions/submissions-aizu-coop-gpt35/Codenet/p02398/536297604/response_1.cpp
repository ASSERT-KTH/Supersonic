#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  int count = 0; // Initialize count to 0

  // Read all three integers in a single statement
  cin >> a >> b >> c;

  // Iterate from 1 to max(b, c)
  for (int s = 1; s <= max(b, c); s++) {
    // Check if both s and c are divisible by s
    if (s <= b && c % s == 0) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}