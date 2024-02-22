#include <algorithm>
#include <cstdio>
using namespace std;

char buffer[4000007]; // buffer to read input
void fastRead_int(int &x) {
  register int c = getchar_unlocked();
  x = 0;
  for(; ((c<48 || c>57)); c = getchar_unlocked());
  for(; c>47 && c<58 ; c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}
void fastWrite_int(int n) {
  if(n == 0) { putchar_unlocked('0'); putchar_unlocked('\n'); return; }
  int i = 12;
  while(n) { buffer[i--] = (n % 10) + '0'; n /= 10; }
  while(buffer[i] != '\n') putchar_unlocked(buffer[++i]);
}

int main() {
  int n, i, f, A[1000001];
  fastRead_int(n);
  for (i = 0; i < n; i++)
    fastRead_int(A[i]);
  std::sort(A, A + n);
  for (i = f = 0; i < n; i++)
    fastWrite_int(A[i]), f = 1;
  puts("");
}