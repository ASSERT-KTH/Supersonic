#include <iostream>
int main() {
  std::ios::sync_with_stdio(false); 
  std::cin.tie(NULL);
  int x;
  std::cin >> x;
  std::cout << x * x * x << "\n";
}