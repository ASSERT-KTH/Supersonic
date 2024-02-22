#include <cstdio>
#include <bitset>
using namespace std;

bitset<4096> d;

int c(char str[12]) {
  int ans = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    ans *= 4;
    switch (str[i]) {
      case 'A':
        ans += 0;
        break;
      case 'C':
        ans += 1;
        break;
      case 'G':
        ans += 2;
        break;
      case 'T':
        ans += 3;
        break;
    }
  }
  return ans;
}

inline void fast_scan(int& number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar_unlocked();
    if (c == '-')
    {
        negative = true;
        c = getchar_unlocked();
    }
    for (; (c > 47 && c < 58); c = getchar_unlocked())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}

inline void fast_print(int number) {
    char buffer[16];
    int idx = 0;
    if (number == 0)
    {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        return;
    }
    else if (number < 0)
    {
        putchar_unlocked('-');
        number *= -1;
    }
    while (number > 0)
    {
        buffer[idx++] = number % 10 + '0';
        number /= 10;
    }
    for (int i = idx - 1; i >= 0; i--)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

int main() {
  int n;
  fast_scan(n);

  char s, str[12];
  while (n--) {
    s = getchar_unlocked();
    while (s == ' ' || s == '\n')
      s = getchar_unlocked();

    int i = 0;
    while (s != ' ' && s != '\n') {
      str[i++] = s;
      s = getchar_unlocked();
    }
    str[i] = '\0';

    if (s == 'i')
      d[c(str)] = true;
    else
      fast_print(d[c(str)]);
  }
  return 0;
}