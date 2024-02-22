#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int min_abcd = min(min(a, b), min(c, d));
  int max_ef = max(e, f);
  cout << a + b + c + d - min_abcd + max_ef << '\n';
  return 0;
}