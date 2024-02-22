#include <cstdio>

bool d[33554432];

int c(const char* str) {
  int ans = *str;
  while (*(++str) != '\0') {
    ans <<= 2;
    ans |= (*str & 3);
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  
  char s[7], str[12];
  
  while (n--) {
    scanf("%s %s", s, str);
    int key = c(str);
    
    if (s[0] == 'i')
      d[key] = true;
    else
      puts(d[key] ? "yes" : "no");
  }
  
  return 0;
}