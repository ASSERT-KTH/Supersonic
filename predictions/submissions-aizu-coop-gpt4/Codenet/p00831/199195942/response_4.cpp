#include <iostream>
#include <vector>
#include <string>
using namespace std;

int damerau_levenshtein_distance(const string &a, const string &b) {
  vector<int> da(256);
  vector<vector<int>> d(a.size() + 2, vector<int>(b.size() + 2));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 0; i <= a.size(); ++i) {
    d[i + 1][1] = i;
    d[i + 1][0] = maxdist;
  }
  for (int i = 0; i <= b.size(); ++i) {
    d[1][i + 1] = i;
    d[0][i + 1] = maxdist;
  }
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i + 1][j + 1] = min({d[i][j] + cost, d[i + 1][j] + 1, d[i][j + 1] + 1,
                             d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
  }
  return d[a.size() + 1][b.size() + 1];
}

void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  for(int i=0; i<n; i++) cin >> name[i];
  int count = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(abs((int)name[i].length() - (int)name[j].length()) <= d &&
         damerau_levenshtein_distance(name[i], name[j]) <= d) {
        ++count;
        cout << name[i] << "," << name[j] << endl;
      }
    }
  }
  cout << count << endl;
}

int main() {
  ios::sync_with_stdio(false);
  for (;;) {
    int n;
    cin >> n;
    if (!n)
      break;
    solve(n);
  }
  return 0;
}