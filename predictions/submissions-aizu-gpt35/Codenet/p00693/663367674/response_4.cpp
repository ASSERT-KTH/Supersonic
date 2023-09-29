#include <algorithm>
#include <bits/stdc++.h>
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
int N, M;
struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};
struct Data {
  char from[9], to[9], message[51];
};
bool strCmp(char *base, char *comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i]) {
      return false;
    }
  }
  return true;
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
  for (int i = 0; str[i] != '\0'; i++) {
    to[i] = str[i];
    to[i + 1] = '\0';
  }
}
void func() {
  int ok_index = 0, not_index = 0;
  Info OK[N], NOT[N];
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }
  char buf[10], from[9], to[9];
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
  for (int i = not_index - 1; i >= 0; i--) {
    for (int k = ok_index - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased == true)
        continue;
      if (strCmp(NOT[i].from, OK[k].from) && strCmp(NOT[i].to, OK[k].to)) {
        OK[k].erased = true;
      }
    }
  }
  for (int i = ok_index - 1; i >= 0; i--) {
    for (int k = not_index - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased == true)
        continue;
      if (strCmp(OK[i].from, NOT[k].from) && strCmp(OK[i].to, NOT[k].to)) {
        NOT[k].erased = true;
      }
    }
  }
  queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);
    bool ok = false, not_ok = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) && ambiguousCmp(OK[i].to, data.to)) {
        ok = true;
        break;
      }
    }
    if (!ok)
      continue;
    for (int i = 0; i < not_index; i++) {
      if (NOT[i].erased)
        continue;
      if (ambiguousCmp(NOT[i].from, data.from) && ambiguousCmp(NOT[i].to, data.to)) {
        not_ok = true;
        break;
      }
    }
    if (!not_ok) {
      Q.push(data);
    }
  }
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