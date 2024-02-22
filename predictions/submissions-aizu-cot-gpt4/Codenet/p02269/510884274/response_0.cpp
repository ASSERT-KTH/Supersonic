#include <iostream>
#define MAX_SIZE 100

bool chk[244140624];
int n;
char ins[MAX_SIZE], s[MAX_SIZE];

int h(char* str) {
  int ret = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    ret *= 5;
    switch(str[i]) {
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