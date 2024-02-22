#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);  // Speed up I/O operations

  const int n_types = 4;
  const int coin_values[n_types] = {10, 50, 100, 500};
  int N, c[n_types], f[n_types] = {0}, pay[n_types], ans[n_types];

  while (true) {
    cin >> N;
    if (N == 0) break;

    int sum = 0;
    for (int i = 0; i < n_types; ++i) {
      cin >> c[i];
      sum += c[i];
    }

    int min_leftover = INT_MAX;
    for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
      for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
        for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
          for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
            int m_pay = 0;
            for (int i = 0; i < n_types; ++i)
              m_pay += coin_values[i] * pay[i];

            if (m_pay >= N) {
              int leftover = m_pay - N;
              int charge[n_types] = {0};
              for (int i = n_types - 1; i >= 0; --i) {
                charge[i] = leftover / coin_values[i];
                leftover %= coin_values[i];
              }

              int total_coins_used = 0;
              for (int i = 0; i < n_types; ++i)
                total_coins_used += pay[i] + charge[i];

              if (min_leftover > sum - total_coins_used) {
                copy(begin(pay), end(pay), begin(ans));
                min_leftover = sum - total_coins_used;
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < n_types; ++i) {
      if (ans[i] > 0)
        cout << coin_values[i] << " " << ans[i] << "\n";
    }
    cout << "\n";
  }

  return 0;
}