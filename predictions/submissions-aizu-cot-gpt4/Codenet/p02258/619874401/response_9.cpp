#include <cstdio>
#define MAX 200000

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int R[MAX], n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &R[i]);
  
  int maxv = R[1] - R[0];
  int minv = R[0];
  
  for (int i = 1; i < n; i++) {
    maxv = (maxv > (R[i] - minv)) ? maxv : (R[i] - minv);
    minv = (minv < R[i]) ? minv : R[i];
  }
  
  printf("%d\n", maxv);
  return 0;
}