#include <iostream>
int main() {
  int a, b;
  std::cin >> a >> b;
  int a_times_2 = a * 2;
  int b_times_2 = b * 2;
  std::cout << (a_times_2 + b_times_2) / 2 << " " << a_times_2 + b_times_2 << std::endl;
}