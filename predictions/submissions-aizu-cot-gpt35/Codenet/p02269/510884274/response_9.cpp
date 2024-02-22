#include <iostream>
#include <string>

bool chk[1000000];

int h(const std::string& s) {
  int ret = 0;
  for (char c : s) {
    ret *= 5;
    switch (c) {
      case 'A':
        ret += 1;
        break;
      case 'C':
        ret += 2;
        break;
      case 'G':
        ret += 3;
        break;
      case 'T':
        ret += 4;
        break;
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  int numQueries;
  std::cin >> numQueries;
  while (numQueries--) {
    std::string operation, sequence;
    std::cin >> operation >> sequence;
    if (operation[0] == 'i') {
      chk[h(sequence)] = true;
    } else {
      std::cout << (chk[h(sequence)] ? "yes" : "no") << '\n';
    }
  }
  return 0;
}