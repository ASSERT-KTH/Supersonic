#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a = 1;
  for (int i = 2; i <= n; ++i) {
    a *= i;
  }
  cout << a << '\n';
  return 0;
}