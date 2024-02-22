#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  for (long long i, n, j[99999], s = 0, a, maxSum = 0;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    for (i = 0, s = 0; i < n; i++) {
      cin >> a;
      s += a;
      maxSum = std::max(maxSum, n * s);
    }
    for (i = n; i > 1; i--)
      cin >> j[--i];
    for (std::sort(j + 1, j + n); n > 0; s += j[n])
      a = std::max(maxSum, a);
  }
  return 0;
}