#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac;
    ac.reserve(n + 1);

    for (int i = 1; i <= n; ++i) {
      long long num;
      cin >> num;
      ac.push_back(num + ac.back());
    }

    long long res = ac[k];
    for (int i = k; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k]);
      ac[i] -= ac[i - k];
    }

    cout << res << endl;
  }
  return 0;
}