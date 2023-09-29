#include <iostream>
#include <cstring>
using namespace std;

int k;
int dif[12];
const int M = 10;
int memo[12][12][12][12][12][2];

int rec(int d, int p, int d0, int d1, int d2, int b) {
  if (p == k) {
    return d;
  }
  if (memo[p][d0][d1][d2][b][d] != -1) {
    return memo[p][d0][d1][d2][b][d];
  }
  int ans = k;
  if (d >= ans) {
    return ans;
  }
  int rot = dif[p];
  if (rot == 0) {
    ans = rec(d, p + 1, d1, d2, 0, 0);
  } else {
    ans = rec(d + 1, p + 1, d1, d2, rot, 1);
    for (int i = 1; i < M; i++) {
      int a0 = d0;
      int a1 = d1;
      int a2 = d2;
      if (b) {
        a1 = (a1 + i) % M;
        a2 = (a2 + i * rot) % M;
      } else {
        a1 = (a1 - i + M) % M;
        a2 = (a2 - i * rot + M) % M;
      }
      int temp_ans = rec(d + 1, p + 1, a0, a1, a2, 1);
      ans = min(ans, temp_ans);
    }
  }
  memo[p][d0][d1][d2][b][d] = ans;
  return ans;
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    cout << rec(0, 0, 0, 0, 0, 0) << endl;
  }
  return 0;
}