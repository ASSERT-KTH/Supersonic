#include <queue>
#include <iostream>
using namespace std;

main() {
  priority_queue<long long> q;
  for (long long i, n, s, a;; cout << a << endl) {
    cin >> n;
    if (!n)
      break;
    for (i = s = 0; i < n - 2; i++) {
      cin >> a;
      s += a;
      q.push(a);
    }
    cin >> a;
    s += a;
    long long max_product = n * s;
    for (; n > 1; n--) {
      s += q.top();
      q.pop();
      max_product = max(n * s, max_product);
    }
    a = max_product;
  }
}