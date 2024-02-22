#include <algorithm>
#include <cstdio>
inline int getint() {
  int num = 0, c;
  while ((c = getchar_unlocked()) < '0' || c > '9');
  do {
    num = num * 10 + c - '0';
  } while ((c = getchar_unlocked()) >= '0' && c <= '9');
  return num;
}
inline void putint(int num) {
  if (num == 0) {
    putchar_unlocked('0');
  } else {
    char str[20]; 
    int i = 0;
    while (num > 0) {
      str[i++] = '0' + (num % 10);
      num /= 10;
    }
    while (--i >= 0) {
      putchar_unlocked(str[i]);
    }
  }
}
int main() {
  int n, i, f, A[1000001];
  n = getint();
  for (i = 0; i < n; i++)
    A[i] = getint();
  std::sort(A, A + n);
  for (i = f = 0; i < n; i++) {
    if (f)
      putchar_unlocked(' ');
    putint(A[i]);
    f = 1;
  }
  putchar_unlocked('\n');
}