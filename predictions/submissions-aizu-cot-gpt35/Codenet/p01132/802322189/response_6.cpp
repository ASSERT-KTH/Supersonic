#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int multipliers[] = {10, 50, 100, 500};

int payment(const vector<int>& p) {
  int result = 0;
  for (int i = 0; i < 4; i++) {
    result += multipliers[i] * p[i];
  }
  return result;
}

vector<int> charge(int m) {
  vector<int> ans(4);
  for (int i = 3; i >= 0; i--) {
    ans[i] = m / multipliers[i];
    m %= multipliers[i];
  }
  return ans;
}

vector<int> _minus(const vector<int>& a, const vector<int>& b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++) {
    ans[i] = a[i] - b[i];
  }
  return ans;
}

vector<int> _plus(const vector<int>& a, const vector<int>& b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++) {
    ans[i] = a[i] + b[i];
  }
  return ans;
}

bool judge(const vector<int>& f, const vector<int>& ch) {
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
  while (N != 0) {
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
      f[0] = (pay[0] > 0);
      for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
        f[1] = (pay[1] > 0);
        for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
          f[2] = (pay[2] > 0);
          for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
            f[3] = (pay[3] > 0);

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
    if (N != 0)
      cout << endl;
  }
}