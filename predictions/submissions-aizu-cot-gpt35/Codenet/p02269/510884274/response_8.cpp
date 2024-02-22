#include <iostream>

bool chk[244140624];
int n;

int h(const char* s) {
  int ret = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    ret <<= 2;
    if (s[i] == 'A')
      ret |= 0;
    else if (s[i] == 'C')
      ret |= 1;
    else if (s[i] == 'G')
      ret |= 2;
    else if (s[i] == 'T')
      ret |= 3;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  while (n--) {
    char ins[2];
    std::cin >> ins;
    const char* s;
    std::cin >> s;
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      std::cout << (chk[h(s)] ? "yes" : "no") << std::endl;
    }
  }
  return 0;
}