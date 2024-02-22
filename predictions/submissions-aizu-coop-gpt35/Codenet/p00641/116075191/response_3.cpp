#include <iostream>
#include <stack>
using namespace std;

const int MOD = 10007;

int n, b[2][100100], f[2][100100];
bool v[100100];

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    
    long long ans = 1;
    
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        stack<tuple<int, int, int, int>> st;
        st.push(make_tuple(i, b[0][i], f[0][i], 1));
        v[i] = true;
        
        while (!st.empty()) {
          auto [s, now, maxi, num] = st.top();
          st.pop();
          
          if (maxi == f[1][s]) {
            num++;
          } else if (maxi < f[1][s]) {
            maxi = f[1][s];
            num = 1;
          }
          
          bool found = false;
          
          for (int j = 0; j < 2; j++) {
            if (!v[b[j][now]]) {
              v[b[j][now]] = true;
              st.push(make_tuple(s, b[j][now], maxi, num));
              found = true;
              break;
            }
          }
          
          if (!found) {
            ans = (ans * num) % MOD;
          }
        }
      }
    }
    
    cout << ans << endl;
  }
}