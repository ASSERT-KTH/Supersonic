#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T>
int __builtin_popcount(T n) {
  return n ? 1 + __builtin_popcount(n & (n - 1)) : 0;
}
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T>
void max_swap(T &a, const T &b) {
  a = max(a, b);
}

template <class T>
void min_swap(T &a, const T &b) {
  a = min(a, b);
}

typedef long long ll;
typedef pair<int, int> pint;

const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

int dpru(int *c, int *v) {
  int dp[334][334];
  for (int i = 0; i <= n; ++i) {
    for (int j = m; j >= 0; --j) {
      dp[i][j] = 0;
      if (i > 0) {
        dp[i][j] = dp[i - 1][j];
        if (j >= c[i - 1]) {
          max_swap(dp[i][j], dp[i][j - c[i - 1]] + v[i - 1]);
        }
      }
    }
  }
  return dp[n][m];
}

int main() {
  // Add optimization directives or pragmas here

  while (cin >> n >> m) {
    cin.ignore();
    int c[333], v[333][3];

    for (int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      scanf("%d", &c[i]);
      for (int j = 0; j < 3; j++) {
        cin >> v[i][j];
      }
    }

    int res = 0;
    for (int i = 0; i < 3; i++) {
      max_swap(res, dpru(c, v[i]));
    }
    cout << res << endl;
  }
}