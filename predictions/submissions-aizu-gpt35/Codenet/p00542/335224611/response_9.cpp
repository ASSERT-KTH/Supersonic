#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int min_1 = min(a, b);
  int min_2 = min(c, d);
  int min_val = (min_1 < min_2) ? min_1 : min_2;
  int ans = a + b + c + d - min_val + max(e, f);
  cout << ans << endl;
  return 0;
}