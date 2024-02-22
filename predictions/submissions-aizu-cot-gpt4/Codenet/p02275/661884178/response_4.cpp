#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);
  int min = 2000000, t;
  std::vector<int> A(10001);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  std::cout << min;
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) { 
      std::cout << ' ' << i; 
    }
  }
  std::cout << std::endl;
  return 0;
}