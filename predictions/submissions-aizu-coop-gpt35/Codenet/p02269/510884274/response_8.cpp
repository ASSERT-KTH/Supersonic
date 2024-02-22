#include <iostream>
#include <bitset>
#include <string>

const int MAX_N = 1000000; // Maximum number of strings

std::bitset<MAX_N> chk;
int n;
std::string ins, s;

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
  std::cin >> n;
  while (n--) {
    std::cin >> ins >> s;
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      std::cout << (chk[h(s)] ? "yes" : "no") << std::endl;
    }
  }
  return 0;
}