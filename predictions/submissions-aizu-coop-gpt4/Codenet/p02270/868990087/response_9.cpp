#include <cstdio>
#include <iostream>
using namespace std;

int check(int N[], int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  int N[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  // Initialize and fill up the lookup table
  int lookup[n+1];
  for (int i = 1; i <= n; ++i) {
    lookup[i] = check(N, i, k, MAX_W);
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) / 2;
    // Refer to the lookup table instead of calling check()
    if (lookup[mid] <= MAX_W) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}