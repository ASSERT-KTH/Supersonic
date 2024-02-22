#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  int ans = a + b + c + d - min(min(a, b), min(c, d)) + max(e, f);
  
  cout << ans << '\n';
  
  return 0;
}