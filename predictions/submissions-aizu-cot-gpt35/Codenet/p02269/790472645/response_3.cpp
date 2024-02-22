#include <iostream>
#include <unordered_map>

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

int dic_op(const char* str) {
  static const int lookup[256] = {
    // Initialize lookup table for character to value mapping
    ['A'] = 1, ['C'] = 2, ['G'] = 3, ['T'] = 4
  };

  int j = 0;
  ull f = 1;
  ull g = 0;
  while (str[j] && lookup[str[j]]) {
    g += f * lookup[str[j]];
    f *= 5;
    j++;
  }
  return g;
}

int main() {
  int n;
  std::cin >> n;

  std::unordered_map<int, int> dic;
  char opstr[7];
  char str[13];

  for (int i = 0; i < n; i++) {
    std::cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic.count(dic_op(str)) > 0)
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }

  return 0;
}