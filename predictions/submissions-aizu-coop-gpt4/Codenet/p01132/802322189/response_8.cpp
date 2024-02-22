#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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

bool judge(int f, vector<int> &ch) {
  for (int i = 0; i < 4; i++)
    if ((f & (1 << i)) && ch[i] > 0)
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
    int mini = 1e+9;
    vector<int> pay(4);
    vector<int> ans(4);
    for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
      for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
        for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
          for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
            int m_pay = 10 * pay[0] + 50 * pay[1] + 100 * pay[2] + 500 * pay[3];
            int n_pay = accumulate(pay.begin(), pay.end(), 0);
            if (m_pay >= N) {
              vector<int> ch = charge(m_pay - N);
              int n_charge = accumulate(ch.begin(), ch.end(), 0);
              if (mini > sum - n_pay + n_charge) {
                int f = 0;
                for (int i = 0; i < 4; i++)
                  if (pay[i] > 0)
                    f |= (1 << i);
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
        cout << (i + 1) * 10 << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (N)
      cout << endl;
  }
  return 0;
}