#include <algorithm>
#include <iostream>
using namespace std;
main() {
  for (long long i, n, j[99999], s, a;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    for (i = s = 0; i++ < n; s += a)
      cin >> a;
    for (i = n; i > 1; cin >> j[--i])
      ;
    for (sort(j, j + n); n > 0; s += j[n])
      a = max(n-- * s, a);
  }
}
