#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // disable synchronization between C and C++ standard streams
  cin.tie(NULL); // untie cin from cout to improve performance
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << i * j << "\n"; // use "\n" instead of endl to avoid flushing the output buffer
    }
  }
  cout.flush(); // manually flush the output buffer at the end of the program
  return 0;
}