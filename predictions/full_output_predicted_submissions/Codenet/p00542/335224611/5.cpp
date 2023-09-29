#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = a + b + c - min(min(a, b), min(c, d)) + max(e, f);
  cout << ans << endl;
  return 0;
}
