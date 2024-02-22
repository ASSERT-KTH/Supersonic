#include <cstdio>

void printArray(int A[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
}

void quickSort(int A[], int low, int high) {
  if (low < high) {
    int pivot = A[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
      if (A[j] < pivot) {
        i++;
        std::swap(A[i], A[j]);
      }
    }
    
    std::swap(A[i + 1], A[high]);
    
    int partitionIdx = i + 1;
    
    quickSort(A, low, partitionIdx - 1);
    quickSort(A, partitionIdx + 1, high);
  }
}

int main() {
  int n, A[1000001];
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  
  quickSort(A, 0, n - 1);
  printArray(A, n);
}