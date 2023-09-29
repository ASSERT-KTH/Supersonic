#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  for (long long i, n, j[99999], s, a;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    for (i = s = 0; i++ < n; s += a)
      cin >> a;
    for (i = n; i > 1; cin >> j[--i])
      ;
    sort(j + 1, j + n);
    a = j[n--] * n + s;
    for (; n > 0; s += j[n])
      a = max(n-- * s + j[n] * (n + 1), a);
  }
  return 0;
}