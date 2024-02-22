#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  for (long long i, n, s, temp, a;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    s = 0;
    a = 0;
    for (i = 0; i < n; ++i) {
      cin >> temp;
      s += temp;
      a = max(a, temp);
    }
    long long max_val = n * s;
    for (i = n; i > 1; --i) {
      cin >> temp;
      a += temp;
    }
    a = max(max_val, a);
  }
  return 0;
}