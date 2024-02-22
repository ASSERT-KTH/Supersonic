#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n, s, a;
  long long j[99999];
  while(cin >> n && n) {
    s = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a;
      s += a;
    }
    for (long long i = 1; i < n; ++i)
      cin >> j[i];
    sort(j + 1, j + n);
    a = n * s;
    for (; n > 0; --n) {
      a = max(a, n * s);
      s -= j[n];
    }
    cout << a << '\n';
  }

  return 0;
}