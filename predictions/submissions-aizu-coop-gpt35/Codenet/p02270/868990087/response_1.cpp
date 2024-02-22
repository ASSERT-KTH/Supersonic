#include <cstdio>
#include <iostream>
using namespace std;

int check(int* N, int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    for (; s + N[i] <= w; ++i) {
      s += N[i];
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int* N = new int[n];
  int MAX_W = 0;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
    MAX_W = max(MAX_W, N[i]);  // Update MAX_W with the maximum value encountered
  }

  int left = 0;
  int right = MAX_W;

  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << right << endl;

  delete[] N;  // Deallocate the dynamically allocated memory

  return 0;
}