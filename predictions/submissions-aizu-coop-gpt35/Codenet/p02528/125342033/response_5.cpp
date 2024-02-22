#include <cstdio>
#include <cstdlib>

void insertionSort(int A[], int n) {
  for (int i = 1; i < n; i++) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int* A = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  insertionSort(A, n);

  printf("%d", A[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

  free(A);

  return 0;
}