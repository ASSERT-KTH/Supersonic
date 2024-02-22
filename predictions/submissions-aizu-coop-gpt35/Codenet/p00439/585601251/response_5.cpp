#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    long long curr_sum = 0;
    long long max_sum = -LLONG_MAX;

    // Read the elements of the array and calculate the cumulative sum
    for (int i = 1; i <= n; ++i) {
      long long num;
      cin >> num;
      curr_sum += num;

      // If i >= k, we can calculate the maximum sum of k consecutive elements
      if (i >= k) {
        if (curr_sum > max_sum) {
          max_sum = curr_sum;
        }
        curr_sum -= ac[i - k + 1]; // Subtract the first element of the window
      }
    }

    cout << max_sum << endl;
  }

  return 0;
}