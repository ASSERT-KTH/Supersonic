#include <iostream>

int main() {
  std::string x;
  std::cin >> x;

  int b = 0, c = 0, d = 0;
  int maxi = 0;

  for (char ch : x) {
    if (ch == 'J') {
      b++;
    } else if (ch == 'O') {
      c++;
    } else if (ch == 'I') {
      d++;
    }

    if (b >= c && c <= d) {
      maxi = std::max(maxi, c);
    }
  }

  std::cout << maxi << std::endl;

  return 0;
}