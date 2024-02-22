#include <bits/stdc++.h>
using namespace std;

// ... (leave the rest of the code unchanged)

int damerau_levenshtein_distance(const string &a, const string &b) {
  array<int, 26> da;
  da.fill(-1);
  vector<vector<int>> d(a.size() + 2, vector<int>(b.size() + 2));

  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 0; i <= a.size(); ++i) {
    d[i+1][1] = i;
    d[i+1][0] = maxdist;
  }
  for (int i = 0; i <= b.size(); ++i) {
    d[1][i+1] = i;
    d[0][i+1] = maxdist;
  }
  
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int i1 = da[b[j-1] - 'a'];
      int j1 = db;
      int cost = 1;
      if (a[i-1] == b[j-1]) {
        cost = 0;
        db = j;
      }
      d[i+1][j+1] = min({d[i][j] + cost, d[i+1][j] + 1, d[i][j+1] + 1, d[i1][j1] + (i - i1 - 1) + 1 + (j - j1 - 1)});
    }
    da[a[i-1] - 'a'] = i;
  }
  
  return d[a.size() + 1][b.size() + 1];
}

void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  for (int i = 0; i < n; ++i) cin >> name[i];
  sort(name.begin(), name.end());

  map<pair<string, string>, int> distance_cache;
  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int distance;
      if (distance_cache.count({name[i], name[j]})) {
        distance = distance_cache[{name[i], name[j]}];
      } else {
        distance = damerau_levenshtein_distance(name[i], name[j]);
        distance_cache[{name[i], name[j]}] = distance;
      }
      if (distance <= d) {
        ++count;
        cout << name[i] << "," << name[j] << endl;
      }
    }
  }
  cout << count << endl;
}

// ... (leave the rest of the code unchanged)