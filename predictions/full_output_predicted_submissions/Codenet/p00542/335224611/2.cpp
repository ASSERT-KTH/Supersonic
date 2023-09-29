#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << a + b + c + d - min(min(a, b), min(c, d)) + max(e, f);
  return 0;
}
