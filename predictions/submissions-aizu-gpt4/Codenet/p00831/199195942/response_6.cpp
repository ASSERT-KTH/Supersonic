#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

int damerau_levenshtein_distance(const string &a, const string &b) {
  const int alphabet_size = 26;
  array<int, alphabet_size> da = {0};
  int maxdist = a.size() + b.size();
  vector<vector<int>> d(a.size()+1, vector<int>(b.size()+1));
  
  d[0][0] = maxdist;
  for (int i = 0; i <= a.size(); ++i) {
    d[i][0] = i;
  }
  for (int i = 0; i <= b.size(); ++i) {
    d[0][i] = i;
  }
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1] - 'a'], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1] - 'a'] = i;
  }
  return d[a.size()][b.size()];
}

void solve(int n, int d, vector<string>& name) {
  sort(name.begin(), name.end());
  int count = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if (damerau_levenshtein_distance(name[i], name[j]) <= d) {
        ++count;
        cout << name[i] << "," << name[j] << '\n';
      }
    }
  }
  cout << count << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, d;
  while (cin >> n >> d && n != 0) {
    vector<string> names(n);
    for(auto& name : names) {
      cin >> name;
    }
    solve(n, d, names);
  }
  return 0;
}