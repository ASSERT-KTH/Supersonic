#include <iostream>
using namespace std;

int main() {
  int a, b, c, s, t;
  cin >> a >> b >> c;
  
  t = 0; // Initialize t to 0
  
  // Find the smallest divisor of c within the range [a, b]
  s = (a % c == 0) ? a : (a + c - (a % c)); 
  
  // Iterate over the divisors of c within the range [a, b]
  for (; s <= b; s += c) {
    t++;
  }
  
  cout << t << endl;
  return 0;
}