#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Optimizing input/output operations
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (cin >> n >> k, n) {
    // Reducing the size of the vector to save memory
    vector<long long> ac(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> ac[i];
      if(i > 0) {
        ac[i] += ac[i - 1];
      }
    }
    
    long long res = -LLONG_MAX;
    for (int i = k - 1; i < n; ++i) {
      long long temp = ac[i];
      // Adjusting the index in the subtraction operation
      if(i >= k) {
        temp -= ac[i - k];
      }
      res = max(res, temp);
    }
    cout << res << '\n';
  }
  return 0;
}