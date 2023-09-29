#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long i, n, j[100000], s, a;
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    s = 0;
    for (i = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    for (i = 1; i < n; i++)
      cin >> j[i];
    sort(j + 1, j + n);
    a = 0;
    for (i = n - 1; i >= 0; i--) {
      s -= j[i + 1];
      a = max(a, s * (i + 1));
    }
    cout << a << endl;
  }
  return 0;
}