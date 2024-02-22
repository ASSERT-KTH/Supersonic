#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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
bool ambiguousCmp(char *base, char *comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}
bool cmp(Info a, Info b) {
  return a.rank < b.rank;
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
  sort(OK, OK + ok_index, cmp);
  sort(NOT, NOT + not_index, cmp);
  int j = 0;
  for (int i = 0; i < ok_index; i++) {
    while (j < not_index && NOT[j].rank < OK[i].rank) {
      j++;
    }
    if (j < not_index && strcmp(NOT[j].from, OK[i].from) == 0 &&
        strcmp(NOT[j].to, OK[i].to) == 0) {
      OK[i].erased = true;
    }
  }
  j = 0;
  for (int i = 0; i < not_index; i++) {
    while (j < ok_index && OK[j].rank < NOT[i].rank) {
      j++;
    }
    if (j < ok_index && strcmp(OK[j].from, NOT[i].from) == 0 &&
        strcmp(OK[j].to, NOT[i].to) == 0) {
      NOT[i].erased = true;
    }
  }
  int count = 0;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);
    bool FLG = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) &&
          ambiguousCmp(OK[i].to, data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    for (int i = 0; i < not_index; i++) {
      if (NOT[i].erased)
        continue;
      if (ambiguousCmp(NOT[i].from, data.from) &&
          ambiguousCmp(NOT[i].to, data.to)) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
      printf("%s %s %s\n", data.from, data.to, data.message);
      count++;
    }
  }
  printf("%d\n", count);
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