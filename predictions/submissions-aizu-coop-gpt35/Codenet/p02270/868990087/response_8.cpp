#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int check(const vector<int>& N, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      // No need for the comparison i == n
      // The loop condition ensures i will never exceed n
    }
  }
  return i;
}

int main() {
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> N(n);  // Use a dynamically allocated array or a vector
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    // Use bit shift operation for faster integer division
    int mid = (left + right) >> 1;
    if (check(N, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}