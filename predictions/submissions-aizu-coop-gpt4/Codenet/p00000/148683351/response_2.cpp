#include <cstdio>

const int START = 1;
const int END = 9;

int main() {
  for (int i = START; i <= END; ++i) {
    for (int j = START; j <= END; ++j) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}