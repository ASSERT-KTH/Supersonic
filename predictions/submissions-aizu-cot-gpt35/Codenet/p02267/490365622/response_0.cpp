#include <stdio.h>
#include <stdbool.h>

int main() {
  int n, q, *S, *T, i, cnt = 0;
  scanf("%d", &n);
  S = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  T = (int*)malloc(q * sizeof(int));
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  // Find maximum element in S
  int max_S = S[0];
  for (i = 1; i < n; i++) {
    if (S[i] > max_S) {
      max_S = S[i];
    }
  }

  // Create boolean array for hash set
  bool* hashSet = (bool*)calloc(max_S + 1, sizeof(bool));

  // Populate hash set with elements of S
  for (i = 0; i < n; i++) {
    hashSet[S[i]] = true;
  }

  // Check if each element of T exists in hash set
  for (i = 0; i < q; i++) {
    if (T[i] <= max_S && hashSet[T[i]]) {
      cnt++;
    }
  }

  printf("%d\n", cnt);

  free(S);
  free(T);
  free(hashSet);

  return 0;
}