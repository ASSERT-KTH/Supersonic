#include <iostream>
#include <string>

int main() {
  int n;
  for (char a, b; std::cin >> n && n; std::cout << std::endl) {
    int d[256] = {};
    for (; n--; ) {
      std::cin >> a >> b;
      if (d[a] == 0) // only calculate and store the difference if it hasn't been done before
        d[a] = b - a;
    }
    std::cin >> n;
    std::string output;
    for (; n--; ) {
      std::cin >> a;
      output += (a + d[a]); // store the adjusted characters in the string
    }
    std::cout << output; // print all characters at once
  }
}