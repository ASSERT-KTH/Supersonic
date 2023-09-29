#include <cstdio>
#include <iostream>
using namespace std;
main() {
  long long n, a = 1;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    a = a * i;
  }
  cout << a << endl;
}
