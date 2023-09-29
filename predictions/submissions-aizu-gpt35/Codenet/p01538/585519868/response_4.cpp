#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
int table[MAX_N + 1];

int digit_product(int n) {
  int res = 1;
  while (n != 0) {
    int d = n % 10;
    n /= 10;
    if (d != 0) {
      res *= d;
    }
  }
  return res;
}

int main() {
  int Q;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    int N;
    scanf("%d", &N);
    int count = 0;
    while (true) {
      if (N <= MAX_N && table[N] > 0) {
        count = table[N] - 1;
        break;
      }
      if (N == 1) {
        break;
      }
      if (N <= MAX_N) {
        table[N] = count + 1;
      }
      N = digit_product(N);
      count++;
    }
    if (N == 1) {
      printf("%d\n", count);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}