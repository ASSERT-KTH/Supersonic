#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long i, n, j[99999], s, a;
  while (cin >> n && n != 0) {
    s = 0;
    for (i = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    for (i = 1; i < n; i++) {
      cin >> j[i];
    }
    sort(j + 1, j + n);
    a = s;
    for (i = n - 1; i > 0; i--) {
      s -= j[i];
      a = max(a, s * (n - i) + j[i] * i);
    }
    cout << a << endl;
  }
  return 0;
}