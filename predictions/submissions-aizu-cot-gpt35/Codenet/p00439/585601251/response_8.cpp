#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac;
    ac.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
      long long x;
      cin >> x;
      if (i > 0) {
        x += ac[i - 1];
      }
      ac.push_back(x);
    }
    auto it = max_element(ac.begin() + k, ac.end());
    cout << *it - ac[it - ac.begin() - k] << endl;
  }
  return 0;
}