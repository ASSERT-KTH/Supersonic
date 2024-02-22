#include <cstdio>

int main() {
  int n, i, A[1000001];

  // Read the input
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", A + i);

  // Sort the array
  for (int j = 0; j < n - 1; j++) {
    for (i = 0; i < n - j - 1; i++) {
      if (A[i] > A[i + 1]) {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
      }
    }
  }

  // Print the sorted array
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}