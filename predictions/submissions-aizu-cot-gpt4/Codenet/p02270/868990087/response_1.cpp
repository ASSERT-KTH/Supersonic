#include <cstdio>
#include <cstdlib>
using namespace std;

inline int check(int N[], int n, int k, int w) {
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
  ios_base::sync_with_stdio(false);
  
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);

  int *N = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }

  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) >> 1;
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%d\n", right);
  free(N);
  return 0;
}