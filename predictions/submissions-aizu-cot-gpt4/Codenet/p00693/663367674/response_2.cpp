#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
int N, M;

struct Data {
  char from[9], to[9], message[51];
};

struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};

bool ambiguousCmp(char *base, char *comp) {
  bool FLG = true;
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i]) {
      if (base[i] == '?') {
      } else {
        FLG = false;
        break;
      }
    }
  }
  if (FLG)
    return true;
  else {
    return false;
  }
}

void func() {
  int ok_index = 0, not_index = 0;
  vector<Info> OK(N), NOT(N);
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }
  char buf[10], from[9], to[9];
  bool FLG;
  for (int i = 0; i < N; i++) {
    cin >> buf >> from >> to;
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
      if (strcmp(NOT[i].from, OK[k].from) == 0 &&
          strcmp(NOT[i].to, OK[k].to) == 0) {
        OK[k].erased = true;
      }
    }
  }
  for (int i = ok_index - 1; i >= 0; i--) {
    for (int k = not_index - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased == true)
        continue;
      if (strcmp(OK[i].from, NOT[k].from) == 0 &&
          strcmp(OK[i].to, NOT[k].to) == 0) {
        NOT[k].erased = true;
      }
    }
  }
  queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    cin >> data.from >> data.to >> data.message;
    FLG = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased == true)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) == true &&
          ambiguousCmp(OK[i].to, data.to) == true) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    FLG = true;
    for (int i = 0; i < not_index; i++) {
      if (NOT[i].erased == true)
        continue;
      if (ambiguousCmp(NOT[i].from, data.from) == true &&
          ambiguousCmp(NOT[i].to, data.to) == true) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
      Q.push(data);
    }
  }
  cout << Q.size() << "\n";
  while (!Q.empty()) {
    cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << "\n";
    Q.pop();
  }
}

int main() {
  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}