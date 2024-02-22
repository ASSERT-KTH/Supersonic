#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int payment(const vector<int>& p) {
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

vector<int> _minus(const vector<int>& a, const vector<int>& b) {
  vector<int> ans(4);
  
  std::transform(a.begin(), a.end(), b.begin(), ans.begin(), std::minus<int>());
  
  return ans;
}

vector<int> _plus(const vector<int>& a, const vector<int>& b) {
  vector<int> ans(4);
  
  std::transform(a.begin(), a.end(), b.begin(), ans.begin(), std::plus<int>());
  
  return ans;
}

bool judge(const vector<int>& f, const vector<int>& ch) {
  int result = std::inner_product(f.begin(), f.end(), ch.begin(), 0);
  
  return result == 0;
}

void findOptimalCombination(int N, vector<int>& c, vector<int>& f, vector<int>& ans, int& mini, int sum, int n_pay) {
  if (f[0] > c[0]) return;
  
  if (n_pay >= N) {
    vector<int> pay = _minus(c, f);
    int m_pay = payment(pay);
    
    if (m_pay < N) return;
    
    vector<int> ch = charge(m_pay - N);
    int n_charge = std::accumulate(ch.begin(), ch.end(), 0);
    
    if (mini > sum - n_pay + n_charge && judge(f, ch)) {
      ans = pay;
      mini = sum - n_pay + n_charge;
    }
  }
  
  for (int i = 0; i <= c[0]; i++) {
    f[0] = i;
    n_pay += i * 10;
    findOptimalCombination(N, c, f, ans, mini, sum, n_pay);
    n_pay -= i * 10;
    f[0] = 0;
  }
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
    int mini = 1e9;
    vector<int> pay(4);
    vector<int> ans(4);
    int n_pay = 0;
    
    findOptimalCombination(N, c, f, ans, mini, sum, n_pay);
    
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
    
    if (N != 0) {
      cout << endl;
    }
  }
}