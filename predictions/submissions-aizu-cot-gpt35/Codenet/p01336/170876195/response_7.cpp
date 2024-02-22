#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

template <class T> void max_swap(T& a, const T& b) {
  if (b > a) {
    a = b;
  }
}

int dpru(int* c, int(*v)[333]) {
  int dp[333][333];
  CLEAR(dp, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i]) {
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i][j]);
      }
    }
  }

  return dp[n][m];
}

int main() {
  while (cin >> n >> m) {
    int c[333];
    int v[3][333];

    cin.ignore();

    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) {
        cin >> v[j][i];
      }
    }

    int res = 0;
    for (int i = 0; i < 3; ++i) {
      max_swap(res, dpru(c, v[i]));
    }
    cout << res << endl;
  }
}