#include <cstdio>
#include <iostream>
using namespace std;
main() {
  long long a = 1;
  int i, n;
  cin >> n;
  for (i = 3; i <= n; i += 2) {
    a = a * i;
  }
  cout << a;
}
