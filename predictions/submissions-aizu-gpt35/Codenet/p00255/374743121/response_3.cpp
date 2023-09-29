#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long i, n, j[99999], s, a;
  while (cin >> n && n != 0) {
    for (i = s = 0; i++ < n; s += a) {
      cin >> a;
    }
    for (i = n; i > 1; i--) {
      cin >> j[i - 1];
    }
    sort(j + 1, j + n);
    for (a = s = 0, i = n; i > 0; i--) {
      s += j[i];
      a = max(a, s * (n - i + 1));
    }
    cout << a << endl;
  }
  return 0;
}