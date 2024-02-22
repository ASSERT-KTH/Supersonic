#include <cstdio>

void quickSort(int A[], int low, int high) {
  if (low < high) {
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
      if (A[j] < pivot) {
        i++;
        std::swap(A[i], A[j]);
      }
    }

    std::swap(A[i + 1], A[high]);

    quickSort(A, low, i);
    quickSort(A, i + 2, high);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int A[1000001];
  for (int i = 0; i < n; i++)
    scanf("%d", A + i);

  quickSort(A, 0, n - 1);

  printf("%d", A[0]);
  for (int i = 1; i < n; i++)
    printf(" %d", A[i]);
  printf("\n");
}