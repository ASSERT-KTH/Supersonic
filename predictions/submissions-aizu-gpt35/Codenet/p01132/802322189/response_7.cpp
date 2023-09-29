#include <bits/stdc++.h>
using namespace std;
int payment(vector<int> p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}
vector<int> charge(int m) {
  vector<int> ans(4);
  ans[3] = m / 500;
  m %= 500;
  ans[2] = m / 100;
  m %= 100;
  ans[1] = m / 50;
  m %= 50;
  ans[0] = m / 10;
  return ans;
}
vector<int> _minus(vector<int> a, vector<int> b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++)
    ans[i] = a[i] - b[i];
  return ans;
}
vector<int> _plus(vector<int> a, vector<int> b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++)
    ans[i] = a[i] + b[i];
  return ans;
}
bool judge(vector<int> &f, vector<int> &ch) {
  for (int i = 0; i < 4; i++)
    if (f[i] == 1 and ch[i] > 0)
      return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  while (N) {
    vector<int> c(4);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    vector<int> ans(4);
    int mini = 1e+9;
    for (int i = 0; i <= c[0]; i++) {
      for (int j = 0; j <= c[1]; j++) {
        for (int k = 0; k <= c[2]; k++) {
          for (int l = 0; l <= c[3]; l++) {
            if (i == 0 && j == 0 && k == 0 && l == 0) continue;
            int m_pay = payment({i, j, k, l});
            if (m_pay < N) continue;
            int n_pay = i + j + k + l;
            auto ch = charge(m_pay - N);
            int n_charge = ch[0] + ch[1] + ch[2] + ch[3];
            if (mini > sum - n_pay + n_charge) {
              if (judge({i > 0, j > 0, k > 0, l > 0}, ch)) {
                ans = {i, j, k, l};
                mini = sum - n_pay + n_charge;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        if (i == 0)
          cout << 10 << " " << ans[i] << endl;
        if (i == 1)
          cout << 50 << " " << ans[i] << endl;
        if (i == 2)
          cout << 100 << " " << ans[i] << endl;
        if (i == 3)
          cout << 500 << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (!N)
      break;
    cout << endl;
  }
}