#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;
int damerau_levenshtein_distance(const string &a, const string &b) {
  int m = a.size(), n = b.size();
  vector<vector<int>> d(m + 1, vector<int>(n + 1));

  for (int i = 0; i <= m; i++)
    d[i][0] = i;
  for (int i = 0; i <= n; i++)
    d[0][i] = i;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost = (a[i - 1] == b[j - 1] ? 0 : 1);
      d[i][j] = min({d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost});
      if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1])
        d[i][j] = min(d[i][j], d[i - 2][j - 2] + cost);
    }
  }
  return d[m][n];
}

void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  for (int i = 0; i < n; i++) cin >> name[i];
  sort(name.begin(), name.end());
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (damerau_levenshtein_distance(name[i], name[j]) <= d) {
        ++count;
        cout << name[i] << "," << name[j] << endl;
      }
    }
  }
  cout << count << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  for (;;) {
    int n;
    cin >> n;
    if (!n)
      break;
    solve(n);
  }
  return 0;
}