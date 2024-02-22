#include <iostream>
#include <unordered_set>

typedef unsigned long long ull;

ull pow(ull x, ull n) {
  ull res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}

ull dic_op(char str[14]) {
  int j;
  ull f = 1;
  ull g = 0;
  for (j = 0;; j++) {
    if (str[j] == 'A')
      g += f * 1;
    else if (str[j] == 'C')
      g += f * 2;
    else if (str[j] == 'G')
      g += f * 3;
    else if (str[j] == 'T')
      g += f * 4;
    else
      break;
    f *= 5;
  }
  return g;
}

int main() {
  int n;
  std::cin >> n;

  std::unordered_set<ull> dic;

  char opstr[7];
  char str[13];

  for (int i = 0; i < n; i++) {
    std::cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.find(dic_op(str)) != dic.end())
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }

  return 0;
}