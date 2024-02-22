#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const vector<int> denominations = {10, 50, 100, 500};

int payment(const vector<int>& p) {
  int total_payment = 0;
  for (int i = 0; i < p.size(); i++) {
    total_payment += denominations[i] * p[i];
  }
  return total_payment;
}

vector<int> charge(int m) {
  vector<int> ans(4);
  for (int i = 3; i >= 0; i--) {
    ans[i] = m / denominations[i];
    m %= denominations[i];
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
    int mini = numeric_limits<int>::max();
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
            int m_pay = payment(pay);
            int n_pay = accumulate(pay.begin(), pay.end(), 0);
            if (m_pay >= N) {
              vector<int> ch = charge(m_pay - N);
              int n_charge = accumulate(ch.begin(), ch.end(), 0);
              if (mini > sum - n_pay + n_charge) {
                if (judge(f, ch)) {
                  ans = pay;
                  mini = sum - n_pay + n_charge;
                }
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
        cout << denominations[i] << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (N != 0) {
      cout << endl;
    }
  }
  return 0;
}