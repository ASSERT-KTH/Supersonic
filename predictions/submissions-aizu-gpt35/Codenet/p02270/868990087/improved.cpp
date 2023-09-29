#include <cstdio>
#include <iostream>
using namespace std;
int check(int P, int N[], int n, int k) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int w = 0;
    while (w + N[i] <= P) {
      w += N[i];
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
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  int left = 0;
  int right = 1000000000;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(mid, N, n, k) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}
