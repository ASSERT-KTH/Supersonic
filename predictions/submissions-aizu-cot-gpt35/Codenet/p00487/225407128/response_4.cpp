#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  vector<ll> a(n), b(n);
  vector<bool> use(n, false);
  
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  
  int ans = 0;
  ll sum = 0;
  int num = 0;
  
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      sum += a[i];
      use[i] = true;
      num++;
    }
    
    if (sum > num * b[i]) {
      sum -= a[i];
      num--;
      continue;
    }
    
    ans = max(ans, num);
  }
  
  cout << ans << endl;
}