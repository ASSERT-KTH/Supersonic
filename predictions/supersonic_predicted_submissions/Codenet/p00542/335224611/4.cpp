#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << a + b + c + d - min(a, b) + max(e, f) << endl;
  return 0;
}
