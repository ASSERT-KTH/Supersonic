#include <bits/stdc++.h>
using namespace std;

int payment(int p[4]) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, int ch[4]) {
  ch[3] = m / 500;
  m -= (m / 500) * 500;
  ch[2] = m / 100;
  m -= (m / 100) * 100;
  ch[1] = m / 50;
  m -= (m / 50) * 50;
  ch[0] = m / 10;
}

bool judge(int f[4], int ch[4]) {
  for (int i = 0; i < 4; i++) {
    if (f[i] == 1 && ch[i] > 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  while (1) {
    int c[4];
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    int f[4] = {0};
    int mini = 1e+9;
    int pay[4] = {0};
    int ans[4] = {0};
    int m_pay = payment(pay);
    int n_pay = accumulate(pay, pay + 4, 0);
    for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
      if (pay[0] > 0) {
        f[0] = 1;
      }
      for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
        if (pay[1] > 0) {
          f[1] = 1;
        }
        for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
          if (pay[2] > 0) {
            f[2] = 1;
          }
          for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
            if (pay[3] > 0) {
              f[3] = 1;
            }
            if (m_pay >= N) {
              int ch[4] = {0};
              charge(m_pay - N, ch);
              int n_charge = accumulate(ch, ch + 4, 0);
              if (mini > sum - n_pay + n_charge && judge(f, ch)) {
                memcpy(ans, pay, sizeof(ans));
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
        if (i == 0) {
          cout << 10 << " " << ans[i] << endl;
        }
        if (i == 1) {
          cout << 50 << " " << ans[i] << endl;
        }
        if (i == 2) {
          cout << 100 << " " << ans[i] << endl;
        }
        if (i == 3) {
          cout << 500 << " " << ans[i] << endl;
        }
      }
    }
    cin >> N;
    if (!N) {
      break;
    }
    cout << endl;
  }
}