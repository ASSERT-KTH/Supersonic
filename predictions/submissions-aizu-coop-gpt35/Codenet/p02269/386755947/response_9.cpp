#include <iostream>
#include <bitset>

int main() {
  std::bitset<33554432> d;
  char k[128];
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;

  int n;
  std::cin >> n;

  char s[7], str[12];
  while (n--) {
    std::cin >> s >> str;
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      std::cout << (d[c(str)] ? "yes" : "no") << std::endl;
  }

  return 0;
}