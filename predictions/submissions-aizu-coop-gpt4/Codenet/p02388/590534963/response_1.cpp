#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  // Use bit-shift and addition instead of multiplication
  cout << (n * (n << 1)) + n << endl;
  return 0;
}