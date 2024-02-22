#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;

int check(int N[], int prefixSum[], int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int idx = upper_bound(prefixSum, prefixSum + n, w) - prefixSum;
    if (idx == n)
      return n;
    i = idx;
  }
  return i;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int N[n];
  int prefixSum[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
    prefixSum[i] = (i > 0) ? prefixSum[i - 1] + N[i] : N[i];
  }
  int left = 0;
  int right = INT_MAX;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, prefixSum, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}