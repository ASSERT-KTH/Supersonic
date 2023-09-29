#include <cstdio>
#include <algorithm>
#define MAX_SIZE 1000001

int main() {
  static int A[MAX_SIZE];
  int n, f = 0;
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);
  
  std::sort(A, A + n);
  
  for (int i = 0; i < n; i++) {
    printf("%s%d", (f++ ? " " : ""), A[i]);
  }
  
  puts("");
  return 0;
}