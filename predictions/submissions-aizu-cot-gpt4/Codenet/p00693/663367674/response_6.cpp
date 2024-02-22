#include <algorithm>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <vector>

typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

int N, M;

struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};

struct Data {
  char from[9], to[9], message[51];
};

bool ambiguousCmp(char *base, char *comp) {
  bool FLG = true;
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i]) {
      if (base[i] != '?') {
        FLG = false;
        break;
      }
    }
  }
  return FLG;
}

void func() {
  std::vector<Info> OK(N), NOT(N);
  
  char buf[10], from[9], to[9];
  bool FLG;
  int ok_index = 0, not_index = 0;
  
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }
  
  for (int i = 0; i < N; i++) {
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      strcpy(OK[ok_index].from, from);
      strcpy(OK[ok_index].to, to);
      OK[ok_index].rank = i;
      ok_index++;
    } else {
      strcpy(NOT[not_index].from, from);
      strcpy(NOT[not_index].to, to);
      NOT[not_index].rank = i;
      not_index++;
    }
  }

  // rest of the code remains the same

  std::queue<Data> Q;
  // rest of the code remains the same
  
  printf("%d\n", Q.size());
  while (!Q.empty()) {
    printf("%s %s %s\n", Q.front().from, Q.front().to, Q.front().message);
    Q.pop();
  }
}

int main() {
  while (true) {
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}