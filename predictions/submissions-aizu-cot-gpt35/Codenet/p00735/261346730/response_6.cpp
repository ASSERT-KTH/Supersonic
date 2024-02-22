#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  list<int> primes;
  bool checked[300000 + 1] = {};

  for (int i = 2; i <= sqrt(300000); i++) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      primes.push_back(i);
      int k = 1;
      while (i * k <= 300000) {
        checked[i * k] = true;
        k++;
      }
    }
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    list<int> ans;
    for (const auto& p : primes) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
  }

  return 0;
}