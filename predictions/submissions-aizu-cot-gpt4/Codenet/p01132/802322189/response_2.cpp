#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  while (cin >> N && N) {
    vector<int> c(4);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    vector<int> f(4, 0);
    int mini = 1e+9;
    vector<int> pay(4);
    vector<int> ans(4);
    for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
      if (pay[0] > 0)
        f[0] = 1;
      for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
        if (pay[1] > 0)
          f[1] = 1;
        for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
          if (pay[2] > 0)
            f[2] = 1;
          for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
            if (pay[3] > 0)
              f[3] = 1;
            int m_pay = 10 * pay[0] + 50 * pay[1] + 100 * pay[2] + 500 * pay[3];
            int n_pay = pay[0] + pay[1] + pay[2] + pay[3];
            if (m_pay >= N) {
              int rest = m_pay - N;
              vector<int> ch = {rest / 10 % 5, rest / 50 % 2, rest / 100 % 5, rest / 500};
              int n_charge = ch[0] + ch[1] + ch[2] + ch[3];
              if (mini > sum - n_pay + n_charge) {
                if (f[0] == 1 && ch[0] > 0) continue;
                if (f[1] == 1 && ch[1] > 0) continue;
                if (f[2] == 1 && ch[2] > 0) continue;
                if (f[3] == 1 && ch[3] > 0) continue;
                ans = pay;
                mini = sum - n_pay + n_charge;
              }
            }
            f[3] = 0;
          }
          f[2] = 0;
        }
        f[1] = 0;
      }
      f[0] = 0;
    }
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        if (i == 0)
          cout << 10 << " " << ans[i] << "\n";
        if (i == 1)
          cout << 50 << " " << ans[i] << "\n";
        if (i == 2)
          cout << 100 << " " << ans[i] << "\n";
        if (i == 3)
          cout << 500 << " " << ans[i] << "\n";
      }
    }
    cout << "\n";
  }
}