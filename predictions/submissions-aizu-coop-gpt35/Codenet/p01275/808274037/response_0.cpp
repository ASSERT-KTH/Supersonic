#include <iostream>
using namespace std;

int k, ans;
int M = 10;
int* dif;
int** memo;

int rec(int d, int p) {
  if (p == k) {
    ans = d;
    return ans;
  }
  if (d >= ans)
    return ans;
  if (memo[d][p] != -1)
    return memo[d][p];
  
  int rot = dif[p];
  if (rot == 0) {
    memo[d][p] = rec(d, p + 1);
    return memo[d][p];
  }

  memo[d][p] = rec(d + 1, p + 1);
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot) % M;
    memo[d][p] = min(memo[d][p], rec(d + 1, p + 1));
  }
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot + M) % M;

  return memo[d][p];
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    dif = new int[k];
    memo = new int*[k];
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
      memo[i] = new int[k];
      for (int j = 0; j < k; j++) {
        memo[i][j] = -1;
      }
    }
    ans = k;
    rec(0, 0);
    cout << ans << endl;

    for (int i = 0; i < k; i++) {
      delete[] memo[i];
    }
    delete[] memo;
    delete[] dif;
  }
}