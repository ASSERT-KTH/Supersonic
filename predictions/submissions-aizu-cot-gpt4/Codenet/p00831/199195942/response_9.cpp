#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)

int damerau_levenshtein_distance(const string &a, const string &b, const int d) {
  if(abs(int(a.size() - b.size())) > d) return d+1;
  vector<int> da(26, 0);
  vector<vector<int>> d(min(a.size(), b.size()) + 1, vector<int>(b.size() + 1));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 0; i <= a.size(); ++i) d[i][0] = i;
  for (int i = 0; i <= b.size(); ++i) d[0][i] = i;
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]-'a'], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]-'a'] = i;
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
      if (damerau_levenshtein_distance(name[i], name[j], d) > d)
        continue;
      ++count;
    }
  }
  sort(name.begin(), name.end());
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      if (damerau_levenshtein_distance(name[i], name[j], d) <= d)
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