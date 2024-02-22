#include <cstdio>
#include <iostream>

int main() {
  int n;
  std::scanf("%d", &n);
  int t, A[10001]{};
  for (int i = 0; i < n; i++) {
    std::scanf("%d", &t);
    A[t]++;
  }
  
  int i = 0;
  while (A[i] == 0) {
    i++;
  }
  
  A[i]--;
  std::cout << i;
  
  for (; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) {
      std::cout << ' ' << i;
    }
  }
  
  std::cout << std::endl;
  return 0;
}