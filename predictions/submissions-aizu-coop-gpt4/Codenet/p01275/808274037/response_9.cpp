#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int k, ans;
vector<int> dif;
vector<vector<int>> dp;
const int M = 10;

int rec(int d, int p) {
  // Check if we've already calculated this state
  if (dp[d][p] != -1)
    return dp[d][p];
    
  if (p == k) {
    ans = d;
    return dp[d][p] = d;
  }
  
  if (d >= ans)
    return dp[d][p] = ans;
    
  int rot = dif[p];
  
  if (rot == 0)
    return dp[d][p] = rec(d, p + 1);
  
  int res = rec(d + 1, p + 1);
  
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] - rot + M) % M;
    
  res = min(res, rec(d + 1, p + 1));    
  
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot) % M;
    
  return dp[d][p] = res;
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    
    dif = vector<int>(k);
    dp = vector<vector<int>>(k+1, vector<int>(k+1, -1));
    
    for (int i = 0; i < k; i++)
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
      
    ans = k;
    rec(0, 0);
    
    cout << ans << endl;
  }
}