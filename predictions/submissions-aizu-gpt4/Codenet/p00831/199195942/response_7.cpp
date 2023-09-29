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
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}
int damerau_levenshtein_distance(const string &a, const string &b) {
  int dp[a.size()+1][b.size()+1];
  for(int i=0;i<=a.size();i++)
      for(int j=0;j<=b.size();j++)
          dp[i][j]=0;
  for(int i=0;i<=a.size();i++)
      dp[i][0]=i;
  for(int j=0;j<=b.size();j++)
      dp[0][j]=j;
  for(int i=1;i<=a.size();i++)
  {
      for(int j=1;j<=b.size();j++)
      {
          int cost = (a[i-1] == b[j-1]) ? 0 : 1;
          dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cost});
          if(i>1 && j>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1])
              dp[i][j]=min(dp[i][j],dp[i-2][j-2]+cost);
      }
  }
  return dp[a.size()][b.size()];
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