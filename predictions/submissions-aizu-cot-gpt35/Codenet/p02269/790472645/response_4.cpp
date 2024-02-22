#include <iostream>
#include <unordered_set>
#include <string>

typedef unsigned long long ull;

ull pow(ull x, ull n) {
  ull res = 1;
  while (n > 0) {
    if (n & 1)
      res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}

ull dic_op(const std::string& str) {
  static const std::unordered_set<char> lookup = {'A', 'C', 'G', 'T'};
  ull f = 1;
  ull g = 0;
  for (char c : str) {
    if (lookup.find(c) == lookup.end())
      break;
    g += f * (lookup.find(c) - lookup.begin() + 1);
    f *= 5;
  }
  return g;
}

int main() {
  int n;
  std::unordered_set<ull> dic;
  std::string opstr, str;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> opstr >> str;
    if (opstr == "insert") {
      dic.insert(dic_op(str));
    } else if (opstr == "find") {
      std::cout << (dic.find(dic_op(str)) != dic.end() ? "yes" : "no") << std::endl;
    }
  }
  return 0;
}