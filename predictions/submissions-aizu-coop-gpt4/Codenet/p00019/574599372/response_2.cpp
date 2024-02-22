#include <iostream>
using namespace std;

int main() {
  long long a = 1;
  int n;
  cin >> n;
  
  // Loop unrolling
  int i = 2;
  for (; i <= n-1; i += 2) {
    a = a * i * (i+1);
  }

  // If n is odd, multiply the last number
  if (i == n) {
    a = a * i;
  }

  cout << a << endl;

  return 0;
}