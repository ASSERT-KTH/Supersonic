#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int target) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return 1;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return 0;
}

int main() {
  int n, *S, q, *T, i, cnt = 0;
  scanf("%d", &n);
  S = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(q * sizeof(int));
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  for (i = 0; i < n; i++)
    cnt += binarySearch(T, q, S[i]);

  printf("%d\n", cnt);

  free(S);
  free(T);

  return 0;
}