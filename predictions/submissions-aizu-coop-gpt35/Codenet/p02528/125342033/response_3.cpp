#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>

int main() {
  int n;
  scanf("%d", &n);

  int* A = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  std::sort(A, A + n);

  std::string sortedElements;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      sortedElements += " ";
    }
    sortedElements += std::to_string(A[i]);
  }

  printf("%s\n", sortedElements.c_str());

  free(A);

  return 0;
}