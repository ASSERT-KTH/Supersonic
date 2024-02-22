#include <iostream>

int main() {
  int w;
  std::cin >> w;
  int n;
  std::cin >> n;
  
  int* startingPoint = new int[w];
  for (int i = 0; i < w; i++) {
    startingPoint[i] = i + 1;
  }
  
  for (int i = 0; i < n; i++) {
    int left, right;
    char dummy;
    std::cin >> left >> dummy >> right;
    
    int temp = startingPoint[left - 1];
    startingPoint[left - 1] = startingPoint[right - 1];
    startingPoint[right - 1] = temp;
  }
  
  for (int i = 0; i < w; i++) {
    std::cout << startingPoint[i] << '\n';
  }
  
  delete[] startingPoint;
  
  return 0;
}