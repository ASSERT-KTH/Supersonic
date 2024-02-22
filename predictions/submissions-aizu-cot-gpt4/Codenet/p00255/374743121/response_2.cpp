#include <iostream>
using namespace std;

int main() {
  long long i, n, s, a;
  while (true) {
    cin >> n;
    if (!n)
      break;
    s = 0;
    a = 0;
    for (i = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    while (n > 0) {
      a = max(n-- * s, a);
    }
    cout << a << endl;
  }
  return 0;
}