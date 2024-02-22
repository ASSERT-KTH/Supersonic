#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int payment(array<int, 4> p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

array<int, 4> charge(int m) {
  array<int, 4> ans = {0, 0, 0, 0};
  int denominations[4] = {500, 100, 50, 10};

  for (int i = 0; i < 4; i++) {
    ans[i] = m / denominations[i];
    m %= denominations[i];
  }

  return ans;
}

bool judge(array<int, 4> &f, array<int, 4> &ch) {
  for (int i = 0; i < 4; i++)
    if (f[i] == 1 and ch[i] > 0)
      return false;
  return true;
}

int main() {
  int N;
  cin >> N;

  while (N) {
    array<int, 4> c;
    int sum = 0;

    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }

    array<int, 4> f = {0, 0, 0, 0};
    int mini = 1e+9;
    array<int, 4> pay;
    array<int, 4> ans;

    for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
      for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
        for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
          for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
            int m_pay = payment(pay);

            if (m_pay >= N) {
              array<int, 4> ch = charge(m_pay - N);
              int n_pay = accumulate(pay.begin(), pay.end(), 0);
              int n_charge = accumulate(ch.begin(), ch.end(), 0);

              if (mini > sum - n_pay + n_charge) {
                if (judge(f, ch)) {
                  ans = pay;
                  mini = sum - n_pay + n_charge;
                }
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        cout << (i == 0 ? 10 : (i == 1 ? 50 : (i == 2 ? 100 : 500))) << " " << ans[i] << endl;
      }
    }

    cin >> N;
    if (N) cout << endl;
  }
}