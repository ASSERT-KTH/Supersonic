#include <algorithm>
#include <iostream>
using namespace std;
main() {
  for (int i, n, j[99999], s, a;; cout << a << endl) {
    scanf("%d", &n);
    if (!n)
      return 0;
    for (i = s = 0; i++ < n; s += a)
      cin >> a;
    for (i = n; i > 1; cin >> j[--i])
      ;
    for (sort(j + 1, j + n); n > 0; s += j[n])
      a = max(n-- * s, a);
  }
  return 0;
}
