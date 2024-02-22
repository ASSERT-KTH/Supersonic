#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
#define debug(x) #x << "=" << (x)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

int damerau_levenshtein_distance(const string &a, const string &b) {
  vector<vector<int>> da(256, vector<int>(a.size()+1, 0));
  vector<vector<int>> d(a.size()+1, vector<int>(b.size()+1, 0));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  rep(i, 0, a.size()+1) {
    d[i][0] = i;
  }
  rep(i, 0, b.size()+1) {
    d[0][i] = i;
  }
  rep(i, 1, a.size()+1) {
    int db = 0;
    rep(j, 1, b.size()+1) {
      int k = da[b[j - 1]][i - 1], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]][i] = i;
  }
  return d[a.size()][b.size()];
}

void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  rep(i, 0, n) cin >> name[i];
  int count = 0;
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      if (damerau_levenshtein_distance(name[i], name[j]) > d)
        continue;
      ++count;
      cout << name[i] << "," << name[j] << endl;
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