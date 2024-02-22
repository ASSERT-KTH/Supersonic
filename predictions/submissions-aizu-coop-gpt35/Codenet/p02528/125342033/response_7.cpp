#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);

  std::vector<int> A(n); // Use a dynamic array instead of a fixed-size array

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[minIndex]) {
        minIndex = j;
      }
    }

    // Swap the minimum element with the current element
    int temp = A[i];
    A[i] = A[minIndex];
    A[minIndex] = temp;

    // Print the current element
    printf(i == 0 ? "%d" : " %d", A[i]);
  }

  puts("");
}