#include <stdio.h>
#include <algorithm>

int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x)
      return 1;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return 0;
}

int main() {
  int n, S[10000], q, T[500], i, j, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  std::sort(S, S+n);  // sort the array S
  scanf("%d", &q);
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++)
    if (binarySearch(S, 0, n-1, T[i]))  // binary search for each element of T in S
      cnt++;
  printf("%d\n", cnt);
  return 0;
}