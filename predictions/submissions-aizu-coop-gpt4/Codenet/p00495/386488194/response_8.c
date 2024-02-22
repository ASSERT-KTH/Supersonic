#include<stdio.h>

int c[5004], d[5004], m, t, u, i, f = "%d\n";
int main(int argc, char *argv[]) {
  for (scanf(f, c); i < *c; scanf(f, ++i + c))
    ;
  m = 0;
  for (; ~scanf(f, &t);) {
    for (u = i = 0; i < *c; i++) {
      if (c[i] == t) {
        d[i] = u + 1;
      } else {
        d[i] = d[i] > u ? d[i] : u;
      }
      u = d[i];
      m = m > u ? m : u;
    }
  }
  printf(f, m);
  return 0;
}