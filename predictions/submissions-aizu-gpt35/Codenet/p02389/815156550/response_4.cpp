#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // to optimize input/output speed
  cin.tie(NULL);
  
  int a, b;
  cin >> a >> b;
  cout << a * b << " " << 2 * (a + b) << endl; // optimized calculation of perimeter
  return 0;
}