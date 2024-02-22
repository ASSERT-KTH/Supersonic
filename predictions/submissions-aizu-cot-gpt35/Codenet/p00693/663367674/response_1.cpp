#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

typedef long long int ll;

#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

struct Info {
  char from[9];
  char to[9];
  int rank;
  bool erased;
};

struct Data {
  char from[9];
  char to[9];
  char message[51];
};

bool strCmp(const char* base, const char* comp) {
  return strcmp(base, comp) == 0;
}

bool ambiguousCmp(const char* base, const char* comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}

void func() {
  int N, M;
  scanf("%d %d", &N, &M);

  std::vector<Info> OK(N);
  std::vector<Info> NOT(N);

  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }

  for (int i = 0; i < N; i++) {
    char buf[10], from[9], to[9];
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      strcpy(OK[i].from, from);
      strcpy(OK[i].to, to);
      OK[i].rank = i;
    } else {
      strcpy(NOT[i].from, from);
      strcpy(NOT[i].to, to);
      NOT[i].rank = i;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased)
        continue;
      if (strCmp(NOT[i].from, OK[k].from) && strCmp(NOT[i].to, OK[k].to)) {
        OK[k].erased = true;
      }
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased)
        continue;
      if (strCmp(OK[i].from, NOT[k].from) && strCmp(OK[i].to, NOT[k].to)) {
        NOT[k].erased = true;
      }
    }
  }

  std::queue<Data> Q;

  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);

    bool FLG = false;

    for (int i = 0; i < N; i++) {
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

    for (int i = 0; i < N; i++) {
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
  while (true) {
    func();
    int N, M;
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0)
      break;
  }
  return 0;
}