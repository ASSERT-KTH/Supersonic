#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> ac[i];
      if (i > 0)
        ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    for (int i = k-1; i < n; ++i) {
      long long temp = ac[i];
      if(i >= k)
        temp -= ac[i - k];
      res = max(res, temp);
    }
    cout << res << endl;
  }
  return 0;
}