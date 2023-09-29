#include <bits/stdc++.h>
using namespace std;
int dp[1001][51][51][51];
void init() {
  memset(dp, -1, sizeof(dp));
}
int payment(vector<int> p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}
vector<int> charge(int m) {
  vector<int> ans(4);
  ans[3] = m / 500;
  m -= (m / 500) * 500;
  ans[2] = m / 100;
  m -= (m / 100) * 100;
  ans[1] = m / 50;
  m -= (m / 50) * 50;
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
int dfs(int N, vector<int>& c, vector<int>& f, vector<int>& pay, int sum) {
    int& res = dp[N][pay[0]][pay[1]][pay[2]];
    if(res != -1) return res;
    if(N == 0) return res = sum;
    int mini = 1e+9;
    for (int i = 0; i < 4; i++) {
        if(pay[i] + 1 <= c[i]) {
            vector<int> newPay = pay;
            newPay[i]++;
            int m_pay = payment(newPay);
            int n_pay = accumulate(newPay.begin(), newPay.end(), 0);
            if (m_pay >= N) {
                vector<int> ch = charge(m_pay - N);
                int n_charge = accumulate(ch.begin(), ch.end(), 0);
                if (judge(f, ch)) {
                  int curr = dfs(0, c, f, newPay, sum - n_pay + n_charge);
                  mini = min(mini, curr);
                }
            } else {
                int curr = dfs(N - m_pay, c, f, newPay, sum);
                mini = min(mini, curr);
            }
        }
    }
    return res = mini;
}
int main() {
  int N;
  cin >> N;
  while (1) {
    vector<int> c(4);
    int sum = 0;
    ;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    vector<int> f(4, 0);
    init();
    vector<int> pay(4);
    int ans = dfs(N, c, f, pay, sum);
    for (int i = 0; i < 4; i++) {
      if (pay[i] > 0) {
        if (i == 0)
          cout << 10 << " " << pay[i] << endl;
        if (i == 1)
          cout << 50 << " " << pay[i] << endl;
        if (i == 2)
          cout << 100 << " " << pay[i] << endl;
        if (i == 3)
          cout << 500 << " " << pay[i] << endl;
      }
    }
    cin >> N;
    if (!N)
      break;
    cout << endl;
  }
}