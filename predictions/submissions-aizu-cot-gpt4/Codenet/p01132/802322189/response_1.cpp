#include <bits/stdc++.h>
using namespace std;
int payment(int p[]) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}
void charge(int m, int ans[]) {
  int temp = m / 500;
  ans[3] = temp;
  m -= temp * 500;
  temp = m / 100;
  ans[2] = temp;
  m -= temp * 100;
  temp = m / 50;
  ans[1] = temp;
  m -= temp * 50;
  ans[0] = m / 10;
}
bool judge(int f[], int ch[]) {
  for (int i = 0; i < 4; ++i)
    if (f[i] == 1 and ch[i] > 0)
      return false;
  return true;
}
int main() {
  int N;
  cin >> N;
  while (1) {
    int c[4], sum = 0, f[4] = {0}, mini = 1e+9, pay[4], ans[4];
    for (int i = 0; i < 4; ++i) {
      cin >> c[i];
      sum += c[i];
    }
    for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
      if (pay[0] > 0)
        f[0] = 1;
      for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
        if (pay[1] > 0)
          f[1] = 1;
        for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
          if (pay[2] > 0)
            f[2] = 1;
          for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
            if (pay[3] > 0)
              f[3] = 1;
            int m_pay = payment(pay);
            int n_pay = accumulate(pay, pay+4, 0);
            if (m_pay >= N) {
              int ch[4];
              charge(m_pay - N, ch);
              int n_charge = accumulate(ch, ch+4, 0);
              if (mini > sum - n_pay + n_charge && judge(f, ch)) {
                ans[0] = pay[0];
                ans[1] = pay[1];
                ans[2] = pay[2];
                ans[3] = pay[3];
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
    int output[] = {10, 50, 100, 500};
    for (int i = 0; i < 4; ++i) {
      if (ans[i] > 0)
        cout << output[i] << " " << ans[i] << endl;
    }
    cin >> N;
    if (!N)
      break;
    cout << endl;
  }
}