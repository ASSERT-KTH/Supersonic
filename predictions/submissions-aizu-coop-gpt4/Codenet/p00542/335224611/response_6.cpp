#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int min_ab = min(a, b);
  int min_cd = min(c, d);
  int max_ef = max(e, f);

  int ans = a + b + c + d - min(min_ab, min_cd) + max_ef;

  cout << ans << endl;

  return 0;
}