#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
const int inf = 1e9;
int damerau_levenshtein_distance(const string &a, const string &b,
                                 const int alphabet_size) {
  unordered_map<int, int> da;
  int d[2][b.size() + 1];
  int maxdist = a.size() + b.size();
  for (int i = 0; i <= b.size(); ++i) {
    d[0][i] = i;
  }
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    d[i % 2][0] = i;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i % 2][j] =
          min({d[(i - 1) % 2][j - 1] + cost, d[i % 2][j - 1] + 1,
               d[(i - 1) % 2][j] + 1,
               d[(i - 1) % 2][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
  }
  return d[a.size() % 2][b.size()];
}
void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  rep(i, 0, n) cin >> name[i];
  sort(name.begin(), name.end());
  int count = 0;
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      if (damerau_levenshtein_distance(name[i], name[j], 26) > d)
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