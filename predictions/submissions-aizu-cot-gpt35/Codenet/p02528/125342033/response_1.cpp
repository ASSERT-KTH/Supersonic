#include <cstdio>

void quickSort(int A[], int low, int high) {
  if (low < high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
      while (i <= j && A[i] <= pivot)
        i++;
      while (i <= j && A[j] > pivot)
        j--;
      if (i < j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }

    int temp = A[j];
    A[j] = A[low];
    A[low] = temp;

    quickSort(A, low, j - 1);
    quickSort(A, j + 1, high);
  }
}

int main() {
  int n, i, f, A[1000001];
  for (scanf("%d", &n), i = 0; i < n; i++)
    scanf("%d", A + i);
  quickSort(A, 0, n - 1);
  for (i = f = 0; i < n; i++)
    printf(f ? " %d" : "%d", A[i]), f = 1;
  puts("");
}