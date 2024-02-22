#include <iostream>
using namespace std;

int main() {
  unsigned long long a = 1;
  int i, n;
  cin >> n;
  
  for (i = 2; i <= n && a != 0; i++) {
    a *= i;
  }
  
  cout << a << endl;
  return 0;
}