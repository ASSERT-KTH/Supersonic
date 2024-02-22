#include <iostream>
#include <unordered_set>

typedef unsigned long long ull;

ull pow(ull x, ull n) {
  ull res = 1;
  ull temp = x;
  while (n > 0) {
    if (n & 1)
      res *= temp;
    temp *= temp;
    n >>= 1;
  }
  return res;
}

int dic_op(char str[14]) {
  int g = 0;
  int factor[] = {1, 1, 2, 3, 4};
  for (int j = 0; str[j] != '\0'; j++) {
    g += factor[str[j] - 'A'] * pow(5, j);
  }
  return g;
}

int main() {
  int n;
  std::unordered_set<int> dic;
  char opstr[7];
  char str[13];
  std::cin >> n;
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