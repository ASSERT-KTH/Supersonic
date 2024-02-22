#include <algorithm>
#include <iostream>
using namespace std;
main() {
  for (int i, n, j[99999], a;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    int s = 0;
    for (i = 0; i < n; cin >> j[i++])
      ;
    sort(j, j + n);
    for (a = 0; n > 0; a = max(n-- * s, a))
      s += j[n];
  }
}