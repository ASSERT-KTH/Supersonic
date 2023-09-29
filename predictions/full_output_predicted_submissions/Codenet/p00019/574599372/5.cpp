#include <cstdio>
#include <iostream>
using namespace std;
main() {
  long long a = 1;
  long long i;
  cin >> a;
  for (i = 2; i <= a; i++) {
    a = a * i;
  }
  cout << a << endl;
}
