#include <iostream>

bool* d;
unsigned char k[128];

unsigned int c(const char* str) {
  unsigned int ans = str[0];
  unsigned int i = 1;
  for (; str[i] != '\0'; i++) {
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
  
  unsigned int n;
  std::cin >> n;
  
  d = new bool[33554432];
  
  char s[2], str[11];
  while (n--) {
    std::cin >> s >> str;
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      std::cout << (d[c(str)] ? "yes" : "no") << std::endl;
  }
  
  delete[] d;
  
  return 0;
}