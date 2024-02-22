#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100005;
vector<int> S;
int n, q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> q;
  
  S.resize(n + 1); // Resize the vector to appropriate size
  
  for (int i = 0; i < q; i++) {
    bool op;
    cin >> op;
    
    if (op) {
      int k;
      cin >> k;
      
      int ans = 0;
      int idx = k;
      while (idx > 0) {
        ans += S[idx];
        idx -= idx & -idx;
      }
      
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      
      for (int i = s; i <= n; i += i & -i)
        S[i] += x;
      
      for (int i = t + 1; i <= n; i += i & -i)
        S[i] += -x;
    }
  }
  
  return 0;
}