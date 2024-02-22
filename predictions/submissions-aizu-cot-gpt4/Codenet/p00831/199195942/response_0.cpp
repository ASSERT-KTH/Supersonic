#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

int damerau_levenshtein_distance(const string &a, const string &b) {
  vector<vector<int>> d(a.size()+1, vector<int>(b.size()+1));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 1; i <= a.size(); ++i) d[i][0] = i;
  for (int i = 1; i <= b.size(); ++i) d[0][i] = i;
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int cost = (a[i - 1] != b[j - 1]);
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1});
    }
  }
  return d[a.size()][b.size()];
}

void solve(int n) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int d;
  cin >> d;
  set<string> names;
  for(int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    names.insert(name);
  }
  int count = 0;
  for(auto i = names.begin(); i != names.end(); ++i) {
    for(auto j = next(i); j != names.end(); ++j) {
      if(abs((int)(i->size() - j->size())) <= d && 
         damerau_levenshtein_distance(*i, *j) <= d) {
        ++count;
        cout << *i << "," << *j << endl;
      }
    }
  }
  cout << count << endl;
}

int main() {
  for (;;) {
    int n;
    cin >> n;
    if (!n)
      break;
    solve(n);
  }
  return 0;
}