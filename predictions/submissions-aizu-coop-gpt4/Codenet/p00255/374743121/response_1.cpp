#include <iostream>
#include <queue>
using namespace std;

main() {
  ios_base::sync_with_stdio(false); // Fast IO
  cin.tie(NULL);
  cout.tie(NULL);
  
  priority_queue<long long> pq;
  long long n, a, s, max_val;

  while (true) {
    cin >> n;
    if (!n)
      break;
    s = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a;
      s += a;
    }
    for (long long i = 1; i < n; i++) {
      cin >> a;
      pq.push(a);
    }
    max_val = 0;
    while (n > 0) {
      max_val = max(n-- * s, max_val);
      s += pq.top();
      pq.pop();
    }
    cout << max_val << "\n";
    while (!pq.empty()) // Clear the priority queue for next iteration
      pq.pop();
  }
}