#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int payment(vector<int> &p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

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

bool judge(vector<int> &f, vector<int> &ch) {
  return all_of(f.begin(), f.end(), [&](int i) { return f[i] == 1 || ch[i] <= 0; });
}

int main() {
  int N;
  cin >> N;
  while (N) {
    vector<int> c(4), f(4, 0), pay(4, 0), ans(4, 0);
    int sum = accumulate(c.begin(), c.end(), 0);
    for (int p = 1; p <= sum && p <= N; ++p) {
      fill(pay.begin(), pay.end(), 0);
      int m_pay = payment(pay);
      if (m_pay >= N) {
        vector<int> ch = charge(m_pay - N);
        if (judge(f, ch)) {
          ans = pay;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      if (ans[i] > 0) {
        cout << (i + 1) * 10 << " " << ans[i] << endl;
      }
    }
    cin >> N;
    if (!N)
      break;
    cout << endl;
  }
}