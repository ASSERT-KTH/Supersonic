
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

bool judge(vector<int> &f, vector<int> &ch) {
  for (int i = 0; i < 4; i++)
    if (f[i] == 1 and ch[i] > 0)
      return false;
  return true;
}

int main() {
  int N;
  cin >> N;
  while (N) {
    vector<int> c(4);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    vector<int> f(4, 0);
    int mini = 1e+9;
    vector<int> ans(4);
    vector<int> pay(4);
    for (int i = 0; i < 4; i++) {
      for (pay[i] = 0; pay[i] <= c[i]; pay[i]++) {
        if (pay[i] > 0)
          f[i] = 1;
        int m_pay = payment(pay);
        int n_pay = accumulate(pay.begin(), pay.end(), 0);
        if (m_pay >= N) {
          vector<int> ch = charge(m_pay - N);
          int n_charge = accumulate(ch.begin(), ch.end(), 0);
          if (mini > sum - n_pay + n_charge && judge(f, ch)) {
            ans = pay;
            mini = sum - n_pay + n_charge;
          }
        }
        f[i] = 0;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        cout << (i+1)*10 << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (N)
      cout << endl;
  }
}