#include <math.h>
#include <stdio.h>
#define MAXN 100000

inline int readInt() {
  int n = 0;
  char c;
  while ((c = getchar_unlocked()) < '0');
  do {
    n = (n << 3) + (n << 1) + (c - '0');
  } while ((c = getchar_unlocked()) >= '0');
  return n;
}

inline void writeInt(int n) {
  if (n == 0) {
    putchar_unlocked('0');
    putchar_unlocked('\n');
    return;
  }
  char buf[11];
  buf[10] = '\n';
  int i = 9;
  while (n) {
    buf[i--] = n % 10 + '0';
    n /= 10;
  }
  while (buf[++i] != '\n') putchar_unlocked(buf[i]);
}

int main(void) {
  int k, n, ans[MAXN];
  double xa, ya, ra, xb, yb, rb, d0, d1, d2, d3;
  n = readInt();
  for (k = 0; k < n; k++) {
    xa = readInt();
    ya = readInt();
    ra = readInt();
    xb = readInt();
    yb = readInt();
    rb = readInt();
    d0 = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    d1 = ra + rb;
    d2 = ra - rb;
    d3 = rb - ra;
    if (d0 > d1) {
      ans[k] = 0;
    } else if (d2 > d0) {
      ans[k] = 2;
    } else if (d3 > d0) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }
  for (k = 0; k < n; k++) {
    writeInt(ans[k]);
  }
  return 0;
}