#include <cstdio>
using namespace std;
bool d[33554432];
char k[128];

int c(char str[12]) {
  int ans = str[0];
  for (int i = 1; str[i] != '\0'; i++) {
    ans <<= 2;
    ans |= k[str[i]];
  }
  return ans;
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;

  int n;
  n = getchar_unlocked() - '0';
  getchar_unlocked(); // To consume the newline character

  char s[2], str[12];
  while (n--) {
    s[0] = getchar_unlocked();
    getchar_unlocked(); // To consume the space between s and str

    int i = 0;
    while ((str[i] = getchar_unlocked()) != '\n') {
      i++;
    }
    str[i] = '\0'; // Null terminate the string

    if (s[0] == 'i')
      d[c(str)] = true;
    else {
      if (d[c(str)]) {
        putchar_unlocked('y');
        putchar_unlocked('e');
        putchar_unlocked('s');
      } else {
        putchar_unlocked('n');
        putchar_unlocked('o');
      }
      putchar_unlocked('\n');
    }
  }
  return 0;
}