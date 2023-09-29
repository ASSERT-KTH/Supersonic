#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long i, n, j[99999], s, a;
  while (true) {
    cin >> n;
    if (!n)
      break;
    for (i = s = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    for (i = n-1; i >= 0; i--)
      cin >> j[i];
    sort(j, j + n);
    a = s * n;
    for (i = 1; i <= n; i++) {
      s -= j[i - 1];
      a = max(a, s * i);
    }
    cout << a << endl;
  }
  return 0;
}