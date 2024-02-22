#include <stdio.h>
#define MAX_NUM 1000000

bool exists[MAX_NUM+1] = {false};

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for (; ((c<48 || c>57)); c = getchar_unlocked());
    for (; c>47 && c<58; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

inline void fastWrite_int(int x) {
    register char buffor[35];
    register int i=0;
    do {
       buffor[i++]=(x%10)+'0';
       x/=10;
    } while(x);
    i--;
    while (i >= 0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}

int main() {
  int n, num, q, cnt = 0;

  fastRead_int(n);
  for (int i = 0; i < n; i++) {
    fastRead_int(num);
    exists[num] = true;
  }

  fastRead_int(q);
  for (int j = 0; j < q; j++) {
    fastRead_int(num);
    if (exists[num]) cnt++;
  }

  fastWrite_int(cnt);
  return 0;
}