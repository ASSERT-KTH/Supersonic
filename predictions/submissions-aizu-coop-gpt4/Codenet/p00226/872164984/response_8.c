#include <bitset>
#include <cstdio>
#include <cstring>

std::bitset<256> R;
int i, h, b;

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    bool temp = R[c] ^= 1 << i % 5;
    b += !temp;
    h += temp;
    if (++i > 9) {
      printf("%d %d\n", h, b - h);
      R.reset();
      i = h = b = 0;
    }
  }
  return 0;
}