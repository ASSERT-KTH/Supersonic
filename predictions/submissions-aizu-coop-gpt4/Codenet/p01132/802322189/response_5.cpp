#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (N != 0) {
    int c[4], f[4] = {0, 0, 0, 0}, ans[4] = {0, 0, 0, 0};
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    int mini = 1e+9;
    for (int pay0 = 0; pay0 <= c[0]; pay0++) {
      f[0] = pay0 > 0 ? 1 : 0;
      int m_pay0 = 10 * pay0;
      for (int pay1 = 0; pay1 <= c[1]; pay1++) {
        f[1] = pay1 > 0 ? 1 : 0;
        int m_pay1 = m_pay0 + 50 * pay1;
        for (int pay2 = 0; pay2 <= c[2]; pay2++) {
          f[2] = pay2 > 0 ? 1 : 0;
          int m_pay2 = m_pay1 + 100 * pay2;
          for (int pay3 = 0; pay3 <= c[3]; pay3++) {
            f[3] = pay3 > 0 ? 1 : 0;
            int m_pay3 = m_pay2 + 500 * pay3;
            int n_pay = pay0 + pay1 + pay2 + pay3;
            if (m_pay3 >= N) {
              int ch[4] = {0, 0, 0, 0};
              int rem = m_pay3 - N;
              for (int i = 3; i >= 0; i--) {
                int coin_val = i == 0 ? 10 : i == 1 ? 50 : i == 2 ? 100 : 500;
                ch[i] = rem / coin_val;
                rem = rem % coin_val;
              }
              int n_charge = ch[0] + ch[1] + ch[2] + ch[3];
              if (mini > sum - n_pay + n_charge) {
                if (!(f[0] == 1 && ch[0] > 0) && !(f[1] == 1 && ch[1] > 0) && !(f[2] == 1 && ch[2] > 0) && !(f[3] == 1 && ch[3] > 0)) {
                  ans[0] = pay0; ans[1] = pay1; ans[2] = pay2; ans[3] = pay3;
                  mini = sum - n_pay + n_charge;
                }
              }
            }
          }
        }
      }
    }
    int coin_vals[4] = {10, 50, 100, 500};
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        cout << coin_vals[i] << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (N != 0) {
      cout << endl;
    }
  }
  return 0;
}