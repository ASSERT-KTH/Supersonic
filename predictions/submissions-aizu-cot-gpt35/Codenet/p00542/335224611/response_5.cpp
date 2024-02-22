#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int min_abcd = min(min(a, b), min(c, d));
  int ans = a + b + c + d - min_abcd + max(e, f);

  cout << ans << endl;
  return 0;
}