#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false); // Disables synchronization with C-style I/O, speeding up cin/cout
  std::cin.tie(nullptr); // Unties cin from cout, potentially speeding up cin

  int n;
  std::cin >> n;

  std::vector<int> A(n);
  for (int i = 0; i < n; i++)
    std::cin >> A[i];

  std::sort(A.begin(), A.end());

  for (int i = 0; i < n; i++) {
    if (i != 0) std::cout << ' ';
    std::cout << A[i];
  }
  std::cout << '\n';
  return 0;
}