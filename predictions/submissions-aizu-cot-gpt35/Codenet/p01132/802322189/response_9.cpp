#include <iostream>
#include <vector>
#include <numeric>

int payment(const std::vector<int>& p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, std::vector<int>& ans) {
  ans[3] = m / 500;
  ans[2] = (m % 500) / 100;
  ans[1] = (m % 100) / 50;
  ans[0] = (m % 50) / 10;
}

void _minus(std::vector<int>& a, const std::vector<int>& b) {
  for (int i = 0; i < 4; i++) {
    a[i] -= b[i];
  }
}

void _plus(std::vector<int>& a, const std::vector<int>& b) {
  for (int i = 0; i < 4; i++) {
    a[i] += b[i];
  }
}

bool judge(const std::vector<int>& f, const std::vector<int>& ch) {
  for (int i = 0; i < 4; i++) {
    if (f[i] == 1 && ch[i] > 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  std::cin >> N;

  while (N != 0) {
    std::vector<int> c(4);
    int sum = 0;

    for (int i = 0; i < 4; i++) {
      std::cin >> c[i];
      sum += c[i];
    }

    std::vector<int> f(4, 0);
    int mini = 1e+9;
    std::vector<int> pay(4);
    std::vector<int> ans(4);
    ans.reserve(4);

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
            int m_pay = payment(pay);
            int n_pay = std::accumulate(pay.begin(), pay.end(), 0);
            if (m_pay >= N) {
              std::vector<int> ch(4);
              charge(m_pay - N, ch);
              int n_charge = std::accumulate(ch.begin(), ch.end(), 0);
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
        if (i == 0) {
          std::cout << 10 << " " << ans[i] << std::endl;
        }
        if (i == 1) {
          std::cout << 50 << " " << ans[i] << std::endl;
        }
        if (i == 2) {
          std::cout << 100 << " " << ans[i] << std::endl;
        }
        if (i == 3) {
          std::cout << 500 << " " << ans[i] << std::endl;
        }
      }
    }

    std::cin >> N;

    if (N == 0) {
      break;
    }

    std::cout << std::endl;
  }

  return 0;
}