#include <cstdio>
#include <vector>
using namespace std;

int check(vector<int>& N, int n, int k, int w) {
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
  
  vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }

  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = left + ((right - left) >> 1); //bit shift instead of division
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%d\n", right);
  return 0;
}