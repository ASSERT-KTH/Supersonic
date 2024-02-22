#include <algorithm>
#include <stdio.h>
#include <set>
#include <queue>
using namespace std;

int n, x, a[30];
set<int> dp;
bool prime[1000001];

void generate_primes() {
  prime[0] = false, prime[1] = false, prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= 1000000; j += 2)
      prime[i * j] = false;
  }
}

int main() {
  generate_primes();
  while (scanf("%d%d", &n, &x), n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      pq.push(a[i]);
    }
    dp.clear(); dp.insert(0);
    for (int i = 1; i <= x; i++) {
      while (!pq.empty() && i >= pq.top()) {
        if (dp.count(i - pq.top())) {
          dp.insert(i);
          break;
        }
        pq.pop();
      }
    }
    for (int i = x; i >= 0; i--) {
      if (dp.count(i) && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}