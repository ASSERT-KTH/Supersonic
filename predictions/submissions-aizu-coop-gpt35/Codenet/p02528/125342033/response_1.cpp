#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  // Dynamically allocate memory for the array based on the input size
  int* A = new int[n];

  for (int i = 0; i < n; i++)
    scanf("%d", A + i);

  // Counting sort algorithm
  const int MAX_VALUE = 1000000;  // Maximum possible value in the input
  int count[MAX_VALUE + 1] = {0};

  for (int i = 0; i < n; i++)
    count[A[i]]++;

  for (int i = 0, f = 0; i <= MAX_VALUE; i++) {
    for (int j = 0; j < count[i]; j++) {
      printf(f ? " %d" : "%d", i);
      f = 1;
    }
  }

  puts("");

  delete[] A;  // Deallocate the dynamically allocated memory

  return 0;
}