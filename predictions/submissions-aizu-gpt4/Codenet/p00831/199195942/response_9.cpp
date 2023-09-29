#include <bits/stdc++.h>
using namespace std;

int damerau_levenshtein_distance(const string &a, const string &b) {
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
  
  for (int i = 0; i <= a.size(); ++i) dp[i][0] = i;
  for (int i = 0; i <= b.size(); ++i) dp[0][i] = i;
  
  for (int i = 1; i <= a.size(); ++i) {
    for (int j = 1; j <= b.size(); ++j) {
      int cost = a[i - 1] != b[j - 1];
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
      
      if(i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1])
        dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + cost);
    }
  }
  
  return dp[a.size()][b.size()];
}

void solve(int n) {
  int d;
  vector<string> name(n);
  cin >> d;
  
  for(auto& s : name) cin >> s;
  
  sort(name.begin(), name.end());
  int count = 0;
  
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(damerau_levenshtein_distance(name[i], name[j]) <= d) {
        cout << name[i] << "," << name[j] << "\n";
        ++count;
      }
    }
  }
  
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while(cin >> n, n) solve(n);
  
  return 0;
}