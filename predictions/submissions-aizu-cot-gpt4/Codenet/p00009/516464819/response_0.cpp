#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
void sieve(int n, vector<int> &prefix) {
  vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  prefix[2] = 1;
  for (int i = 3; i <= n; i += 2)
    prefix[i] = prefix[i-1] + v[i], prefix[i+1] = prefix[i];
}
int main() {
  vector<int> inputs;
  int mx = 0;
  for (int x; cin >> x;)
    inputs.push_back(x), mx = max(mx, x);
  vector<int> prefix(mx + 1, 0);
  sieve(mx, prefix);
  for (auto x : inputs)
    cout << prefix[x] << endl;
  return 0;
}