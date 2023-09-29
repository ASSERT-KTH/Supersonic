#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = a + b + c + d - min(min(a, b), min(c, d)) + max(e, f);
  cout << ans << endl;
  return 0;
}
