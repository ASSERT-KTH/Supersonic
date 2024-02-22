#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 128;
const int MAX_M = 20;
const int INF = 100;

int dp[MAX_N][1 << MAX_M];
string qes[MAX_N];

int search(vector<int>& vi, int depth, int used, int m, int n) {
  if (dp[vi[0]][used] != INF)
    return dp[vi[0]][used];
  if (vi.size() > (1 << (m - depth)))
    return INF;
  if (vi.size() == 1)
    return depth;
  int res = INF;
  for (int mask = 0; mask < (1 << m); mask++) {
    if ((used & (1 << mask)) == 0) {
      vector<int> a, b;
      for (int j = 0; j < vi.size(); j++) {
        if (qes[vi[j]][mask] == '0')
          a.push_back(vi[j]);
        else
          b.push_back(vi[j]);
      }
      if (a.empty() || b.empty())
        continue;
      int a_res = search(a, depth + 1, used | (1 << mask), m, n);
      int b_res = search(b, depth + 1, used | (1 << mask), m, n);
      res = min(res, max(a_res, b_res));
    }
  }
  return dp[vi[0]][used] = res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << m); j++) {
        dp[i][j] = INF;
      }
    }
    cout << search(vi, 0, 0, m, n) << endl;
  }
}