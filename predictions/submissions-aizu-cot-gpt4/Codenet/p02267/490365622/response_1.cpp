#include <stdio.h>
#include <algorithm>

bool binary_search(int* arr, int size, int key) {
  int left = 0;
  int right = size;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] == key)
      return true;
    else if (key < arr[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return false;
}

int main() {
  int n, S[10000], q, T[500], i, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  std::sort(S, S+n);
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);
  for (i = 0; i < q; i++)
    if (binary_search(S, n, T[i]))
      cnt++;
  printf("%d\n", cnt);
  return 0;
}