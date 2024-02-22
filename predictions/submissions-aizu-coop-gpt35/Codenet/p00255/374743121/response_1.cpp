#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  for (long long i, n, s, a; cin >> n && n != 0; cout << a << endl) {
    vector<long long> j(n);
    for (i = 1, s = 0; i < n; ++i) {
      cin >> j[i];
      s += j[i];
    }
    sort(j.begin() + 1, j.end());
    a = n * s;
    for (i = n; i > 0; --i)
      a = max(i * s + j[i], a);
  }
  return 0;
}