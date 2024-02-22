#include <cstdio>
using namespace std;

int check(int* N, int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (i < n && s + N[i] <= w)
      s += N[i++];
    if (i == n)
      return n;
  }
  return i;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  int* N = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }

  int left = 0;
  int right = 1000000000; // used the value of MAX_W directly
  
  while (left < right) {
    int mid = left + ((right - left) >> 1); // right shift operation
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  
  printf("%d\n", right);
  delete[] N; // free the memory
  return 0;
}