#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<int, bool> d;
std::unordered_map<char, int> k = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int c(const std::string& str) {
  int ans = str[0];
  for (size_t i = 1; i < str.size(); ++i) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;

  std::string s, str;
  while (n--) {
    std::cin >> s >> str;
    if (s == "i")
      d[c(str)] = true;
    else
      std::cout << (d[c(str)] ? "yes\n" : "no\n");
  }
  return 0;
}