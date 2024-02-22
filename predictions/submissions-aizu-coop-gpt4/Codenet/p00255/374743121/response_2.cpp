#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  for (long long i, n, s, a; cin >> n && n != 0; cout << a << endl) {
    vector<long long> j(n);
    for (i = s = 0; i < n; i++) {
      cin >> a;
      s += a;
      j[i] = a;
    }
    sort(j.begin(), j.end());
    for (a = 0; n > 0; s += j[n])
      a = max(n-- * s, a);
  }
  return 0;
}