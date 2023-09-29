#include <iostream>
#include <vector>
#include <algorithm>
#define r(i, n) for (auto i = 0; i < n; i++)
#define s(c) static_cast<int>((c).size())

int main() {
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  r(i, n) { std::cin >> A[i]; }
  std::sort(A.begin(), A.end());
  r(i, n) {
    if(i != 0) std::cout << ' ';
    std::cout << A[i];
  }
  std::cout << '\n';
  return 0;
}