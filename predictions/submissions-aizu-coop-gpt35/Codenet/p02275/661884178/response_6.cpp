#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  int min = 2000000;
  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
    if (A[i] < min)
      min = A[i];
  }

  std::vector<int> counts(min + 1); // Using min + 1 as the size of counts vector

  for (int i = 0; i < n; i++) {
    counts[A[i]]++;
  }

  counts[min]--;

  std::cout << min;
  
  for (int i = min; i < counts.size(); i++) {
    for (int j = 0; j < counts[i]; j++) {
      std::cout << ' ' << i;
    }
  }
  
  std::cout << std::endl;
  return 0;
}