#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long i, n, j[99999], s, a;
  while (cin >> n && n) {
    for (i = s = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    for (i = 1; i < n; i++)
      cin >> j[i];
    sort(j + 1, j + n);
    for (i = n - 1, a = s; i > 0; i--) {
      s -= j[i];
      a = max(a, i * s);
    }
    cout << a << endl;
  }
  return 0;
}