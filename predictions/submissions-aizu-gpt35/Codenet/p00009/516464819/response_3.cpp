#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.push_back(i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  vector<int> primes;
  sieve(*max_element(nums.begin(), nums.end()), primes);
  unordered_set<int> prime_set(primes.begin(), primes.end());
  for (int num : nums) {
    int count = 0;
    for (int prime : primes) {
      if (prime > num) {
        break;
      }
      if (prime_set.count(num - prime)) {
        ++count;
      }
    }
    cout << count << '\n';
  }
  return 0;
}