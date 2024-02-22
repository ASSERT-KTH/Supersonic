#include <cstdio>

// QuickSort implementation
void quicksort(int* arr, int left, int right) {
  if (left >= right) return;

  int pivot = arr[left];
  int i = left;
  int j = right;

  while (i < j) {
    while (i < j && arr[j] >= pivot) j--;
    while (i < j && arr[i] <= pivot) i++;
    if (i < j) std::swap(arr[i], arr[j]);
  }

  std::swap(arr[left], arr[i]);
  quicksort(arr, left, i - 1);
  quicksort(arr, i + 1, right);
}

int main() {
  int n;
  scanf("%d", &n);

  int* A = new int[n];
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);

  quicksort(A, 0, n - 1);

  for (int i = 0; i < n; i++) printf("%d ", A[i]);
  puts("");

  delete[] A;
}