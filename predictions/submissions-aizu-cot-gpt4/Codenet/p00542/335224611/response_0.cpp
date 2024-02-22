#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e, f;
  cin >> e >> f;
  int ans = a + b + c + d - min({a, b, c, d}) + max(e, f);
  cout << ans << endl;
  return 0;
}