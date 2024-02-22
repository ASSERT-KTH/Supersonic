#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  // Find minimum of a,b and c,d and then find minimum of these two
  int min1 = min(a, b);
  int min2 = min(c, d);
  int ans = a + b + c + d - min(min1, min2);
  
  // Find maximum of e and f
  if(e>f)
    ans += e;
  else
    ans += f;
    
  cout << ans << endl;
  return 0;
}