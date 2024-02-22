#include <cstdio>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);
  int min = 2000000, t;
  std::vector<int> A(n+1, 0); // dynamically allocate based on n
  for (int i = 0; i < n; i++) { // replace macro with normal loop
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  printf("%d", min);
  for (int i = min; i <= n; i++) { // replace macro with normal loop
    for (int j = 0; j < A[i]; j++) { 
      printf(" %d", i);
    }
  }
  printf("\n");
  return 0;
}