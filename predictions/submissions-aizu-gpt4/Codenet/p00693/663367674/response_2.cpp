#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};
struct Data {
  char from[9], to[9], message[51];
};
bool strCmp(const char *base, const char *comp) {
  return strcmp(base,comp) == 0;
}
bool ambiguousCmp(const char *base, const char *comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}
void func(int N, int M) {
  vector<Info> OK(N), NOT(N);
  char buf[10];
  bool FLG;
  int ok_index = 0, not_index = 0;
  for (int i = 0; i < N; i++) {
    scanf("%s %s %s", buf, OK[ok_index].from, OK[ok_index].to);
    if (buf[0] == 'p') {
      OK[ok_index++].rank = i;
    } else {
      NOT[not_index].from = OK[ok_index].from;
      NOT[not_index].to = OK[ok_index].to;
      NOT[not_index++].rank = i;
    }
  }
  for (int i = not_index - 1; i >= 0; i--) {
    for (int k = ok_index - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased)
        continue;
      if (strCmp(NOT[i].from, OK[k].from) && strCmp(NOT[i].to, OK[k].to)) {
        OK[k].erased = true;
      }
    }
  }
  for (int i = ok_index - 1; i >= 0; i--) {
    for (int k = not_index - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased)
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
    FLG = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) && ambiguousCmp(OK[i].to, data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    FLG = true;
    for (int i = 0; i < not_index; i++) {
      if (NOT[i].erased)
        continue;
      if (ambiguousCmp(NOT[i].from, data.from) && ambiguousCmp(NOT[i].to, data.to)) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
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
  int N, M;
  while (scanf("%d %d", &N, &M), N || M)
    func(N,M);
  return 0;
}