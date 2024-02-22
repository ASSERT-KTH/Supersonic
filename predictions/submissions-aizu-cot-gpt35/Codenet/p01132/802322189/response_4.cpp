#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int payment(const int* p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, int* ans) {
  ans[3] = m / 500;
  m %= 500;
  ans[2] = m / 100;
  m %= 100;
  ans[1] = m / 50;
  m %= 50;
  ans[0] = m / 10;
}

bool judge(const int* f, const int* ch) {
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
  while (N) {
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
    int m_pay, n_pay, n_charge;
    for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
      f[0] = (pay[0] > 0);
      for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
        f[1] = (pay[1] > 0);
        for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
          f[2] = (pay[2] > 0);
          for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
            f[3] = (pay[3] > 0);
            m_pay = payment(pay);
            n_pay = accumulate(pay, pay + 4, 0);
            if (m_pay >= N) {
              charge(m_pay - N, ans);
              n_charge = accumulate(ans, ans + 4, 0);
              if (mini > sum - n_pay + n_charge && judge(f, ans)) {
                copy(pay, pay + 4, ans);
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