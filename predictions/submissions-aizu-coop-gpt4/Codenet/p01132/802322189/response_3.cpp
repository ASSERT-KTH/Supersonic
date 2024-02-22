#include <iostream>
using namespace std;
int pay[4], c[4], f[4], ans[4];
int table_pay[4][5001], table_charge[4][5001]; // cache tables for pay and charge

void calculate_payment_and_charge() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= c[i]; j++) {
      table_pay[i][j] = 10 * j;
      table_charge[i][j] = j / 500;
    }
  }
}

void compute(int N) {
  int mini = 1e9;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= c[i]; j++) {
      pay[i] = j;
      int m_pay = table_pay[i][j];
      int n_pay = j;
      if (m_pay >= N) {
        int ch = table_charge[i][m_pay - N];
        int n_charge = ch;
        if (mini > c[i] - n_pay + n_charge) {
          ans[i] = pay[i];
          mini = c[i] - n_pay + n_charge;
        }
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 4; i++) cin >> c[i];
  calculate_payment_and_charge();
  while (N) {
    compute(N);
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        cout << 10 * (i + 1) << " " << ans[i] << endl;
      }
    }
    cin >> N;
  }
  return 0;
}