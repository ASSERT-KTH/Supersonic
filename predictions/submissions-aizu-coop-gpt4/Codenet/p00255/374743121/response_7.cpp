#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  while (true) {
    long long n, s = 0, a;
    cin >> n;
    if (n == 0) break;
    
    vector<long long> jVec(n);
    priority_queue<long long> pq;

    for (long long i = 0; i < n; i++) {
      cin >> a;
      s += a;
      cin >> jVec[i];
      pq.push(jVec[i]);
    }

    a = 0;
    while (!pq.empty()) {
      a = max(n-- * s, a);
      s += pq.top();
      pq.pop();
    }
    cout << a << endl;
  }
  return 0;
}