#include <iostream>
int main() {
  int x, y;
  std::ios_base::sync_with_stdio(false); //To disable synchronization between C and C++ standard streams
  std::cin.tie(NULL); //To untie input stream from output stream
  std::cout.tie(NULL); //To untie output stream from input stream
  std::cin >> x;
  y = x * x * x;
  std::cout << y << '\n'; //Using single quotes instead of double quotes for newline character to save memory
  return 0;
}