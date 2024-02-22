#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<int> nums(n);
    for (int& num : nums) cin >> num;
    long long current_sum = 0, previous_sum = 0;
    for (int i = 0; i < k; ++i) current_sum += nums[i];
    long long max_sum = current_sum;
    for (int i = k; i < n; ++i) {
      current_sum += nums[i];
      previous_sum += nums[i - k];
      max_sum = max(max_sum, current_sum - previous_sum);
    }
    cout << max_sum << endl;
  }
  return 0;
}