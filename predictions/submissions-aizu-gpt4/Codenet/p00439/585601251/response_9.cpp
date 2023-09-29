#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for (; ((c < 48 || c > 57)); c = getchar_unlocked());
    for (; c > 47 && c < 58; c = getchar_unlocked()) {x = (x << 1) + (x << 3) + c - 48;}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (true) {
    fastRead_int(n);
    fastRead_int(k);
    if (n == 0) break;

    vector<long long> ac(n + 1, 0);
    long long temp;
    for (int i = 1; i <= n; ++i) {
      fastRead_int(temp);
      ac[i] = temp + ac[i - 1];
    }

    long long res = ac[k];
    for (int i = k + 1; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k]);
    }

    cout << res << "\n";
  }

  return 0;
}