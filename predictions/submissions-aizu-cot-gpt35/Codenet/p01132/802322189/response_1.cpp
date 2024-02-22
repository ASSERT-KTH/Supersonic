#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> c;
vector<int> ans;
int mini;

void generatePayment(int idx, vector<int>& pay, int sum, int m_pay) {
  if (idx == 4) {
    int n_pay = sum;
    if (m_pay >= N) {
      vector<int> ch = {0, 0, 0, 0};
      ch[3] = m_pay / 500;
      m_pay %= 500;
      ch[2] = m_pay / 100;
      m_pay %= 100;
      ch[1] = m_pay / 50;
      m_pay %= 50;
      ch[0] = m_pay / 10;
      
      int n_charge = ch[0] + ch[1] + ch[2] + ch[3];
      if (mini > sum - n_pay + n_charge && ch[0] <= c[0] && ch[1] <= c[1] && ch[2] <= c[2] && ch[3] <= c[3]) {
        ans = pay;
        mini = sum - n_pay + n_charge;
      }
    }
    return;
  }
  
  for (int i = 0; i <= c[idx]; i++) {
    pay[idx] = i;
    if (i > 0) {
      sum += i;
    }
    generatePayment(idx + 1, pay, sum, m_pay + i * (10 + 40 * (idx > 0) + 90 * (idx > 1) + 450 * (idx > 2)));
    if (i > 0) {
      sum -= i;
    }
  }
}

int main() {
  cin >> N;
  while (1) {
    c.resize(4);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }
    
    ans = {0, 0, 0, 0};
    mini = 1e+9;
    vector<int> pay(4);
    generatePayment(0, pay, 0, 0);
    
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
    if (!N)
      break;
    cout << endl;
  }
}