#include <cstdio>

void quicksort(int* arr, int left, int right) {
  if (left < right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }

    std::swap(arr[i + 1], arr[right]);

    quicksort(arr, left, i);
    quicksort(arr, i + 2, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  quicksort(A, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  puts("");
}