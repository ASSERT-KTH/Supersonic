#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool solve(vector<int>& nums, vector<vector<int>>& memo, int i, int m) {
  if (m == 0) {
    return true;
  }
  
  if (i == 0 || m < 0) {
    return false;
  }
  
  if (memo[i][m] != -1) {
    return memo[i][m];
  }
  
  bool include = solve(nums, memo, i - 1, m - nums[i - 1]);
  bool exclude = solve(nums, memo, i - 1, m);
  
  memo[i][m] = include || exclude;
  return memo[i][m];
}

bool subsetSum(vector<int>& nums, int target) {
  int n = nums.size();
  vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
  return solve(nums, memo, n, target);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }
  
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (subsetSum(nums, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}