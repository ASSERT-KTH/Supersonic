#include <iostream>
using namespace std;

int main() {
  int a, b, e, f;
  cin >> a >> b >> e >> f;
  
  int min_val = min(a, b);
  int max_val = max(e, f);
  int ans = a + b - min_val + max_val;
  
  cout << ans << endl;
  return 0;
}