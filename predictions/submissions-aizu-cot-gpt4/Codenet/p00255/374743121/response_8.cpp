#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long n, s, a;
  while (true) {
    cin >> n;
    if (!n)
      break;
    vector<long long> j(n);
    for (s = a = 0; n-- > 0; s += a) {
      cin >> a;
      j[n] = a;
    }
    sort(j.begin(), j.end());
    for (n = j.size(); n > 0; --n)
      a = max(n * s, a);
    cout << a << endl;
  }
  return 0;
}