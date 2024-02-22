#include <cstdio>
#include <bitset>
using namespace std;

bitset<1 << 25> d;
char k[128];

int c(const char* str) {
  int ans = *str++;
  while (*str != '\0') {
    ans <<= 2;
    ans += k[*str++];
  }
  return ans;
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  
  int n;
  scanf("%d", &n);
  
  char s[7], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");
  }
  
  return 0;
}