#include <iostream>
using namespace std;
main() {
  long long a = 1;
  int i, n;
  cin >> n;
  for (i = 2; i <= n; i++) {
    a = a * i;
  }
  cout << a << endl;
}
