#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  int minOfFirstFour = min(min(a, b), min(c, d));
  int maxOfLastTwo = max(e, f);
  
  int ans = a + b + c + d - minOfFirstFour + maxOfLastTwo;
  
  cout << ans << '\n';

  return 0;
}