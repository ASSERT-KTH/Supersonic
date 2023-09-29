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
  int n, k;
  scanf("%d %d", &n, &k);
  int N[n];
  int sum = 0, maxn = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
    sum += N[i];
    maxn = max(maxn, N[i]);
  }
  int left = maxn, right = sum;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}