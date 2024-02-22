#include <bitset>
#include <iostream>
#include <string>

std::bitset<33554432> d;
std::array<int, 128> k;

int c(const std::string& str) {
  int ans = str[0];
  for (int i = 1; i < str.size(); i++) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;

  int n;
  std::cin >> n;
  std::string s, str;
  
  while (n--) {
    std::cin >> s >> str;
    if (s == "i")
      d[c(str)] = true;
    else
      std::cout << (d[c(str)] ? "yes" : "no") << std::endl;
  }

  return 0;
}