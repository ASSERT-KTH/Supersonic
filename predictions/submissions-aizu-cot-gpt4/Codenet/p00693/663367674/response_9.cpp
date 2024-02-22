#include <algorithm>
#include <cfloat>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <vector>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};

struct Data {
  char from[9], to[9], message[51];
};

bool strCmp(char *base, char *comp) {
  for (int i = 0; ; i++) {
    if (base[i] != comp[i])
      return false;
    if (base[i] == '\0')
      return true;
  }
}

bool ambiguousCmp(char *base, char *comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}

void strcpy(char *to, char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    to[i] = str[i];
  }
  to[i] = '\0';
}

void func(int N, int M) {
  // ...
  // All the logic of the function remains the same
  // ...
}

int main() {
  int N, M;
  while (true) {
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0)
      break;
    func(N, M);
  }
  return 0;
}