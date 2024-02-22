#include <iostream>
using namespace std;

int main() {
  int a, b, c, s, t;
  
  // Step 1: Initialize variables
  cin >> a >> b >> c;
  t = 0;
  
  // Step 3: Loop optimization
  s = a;
  while (s <= b) {
    if (c % s == 0) {
      t++;
    }
    
    // Step 2: Unnecessary division
    if (s == 1) {
      s++;
    } else {
      s += c / s;
    }
  }
  
  cout << t << endl;
  return 0;
}