#include <stdio.h>
int main() {
  int i, n, q, C = 0;
  scanf("%d", &n);
  int S[n]; // allocate array after scanning array size
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  int T[q]; // allocate array after scanning array size
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  for (i = 0; i < q; i++) { // loop over T array
    int l = 0, r = n - 1;
    while (l <= r) { // use binary search for each element in T
      int mid = (l + r) / 2;
      if (S[mid] == T[i]) {
        C++;
        break;
      }
      else if (S[mid] < T[i]) {
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
  }
  printf("%d\n", C);
  return 0;
}