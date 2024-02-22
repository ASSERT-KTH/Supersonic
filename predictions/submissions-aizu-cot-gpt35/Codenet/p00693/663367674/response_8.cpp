#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

struct Info {
  std::string from, to;
  int rank;
  bool erased;
};

struct Data {
  std::string from, to, message;
};

bool ambiguousCmp(const std::string& base, const std::string& comp) {
  bool FLG = true;
  for (int i = 0; i < base.size(); i++) {
    if (base[i] != comp[i]) {
      if (base[i] == '?') {
      } else {
        FLG = false;
        break;
      }
    }
  }
  return FLG;
}

void func() {
  int N, M;
  scanf("%d %d", &N, &M);

  std::vector<Info> OK(N), NOT(N);
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }

  for (int i = 0; i < N; i++) {
    char buf[10], from[9], to[9];
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      OK[i].from = from;
      OK[i].to = to;
      OK[i].rank = i;
    } else {
      NOT[i].from = from;
      NOT[i].to = to;
      NOT[i].rank = i;
    }
  }

  for (int i = NOT.size() - 1; i >= 0; i--) {
    for (int k = OK.size() - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased == true)
        continue;
      if (NOT[i].from == OK[k].from && NOT[i].to == OK[k].to) {
        OK[k].erased = true;
      }
    }
  }

  for (int i = OK.size() - 1; i >= 0; i--) {
    for (int k = NOT.size() - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased == true)
        continue;
      if (OK[i].from == NOT[k].from && OK[i].to == NOT[k].to) {
        NOT[k].erased = true;
      }
    }
  }

  std::vector<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", &data.from[0], &data.to[0], &data.message[0]);
    bool FLG = false;
    for (int i = 0; i < OK.size(); i++) {
      if (OK[i].erased == true)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) && ambiguousCmp(OK[i].to, data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    FLG = true;
    for (int i = 0; i < NOT.size(); i++) {
      if (NOT[i].erased == true)
        continue;
      if (ambiguousCmp(NOT[i].from, data.from) && ambiguousCmp(NOT[i].to, data.to)) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
      Q.push_back(data);
    }
  }

  printf("%d\n", Q.size());
  for (const auto& data : Q) {
    printf("%s %s %s\n", data.from.c_str(), data.to.c_str(), data.message.c_str());
  }
}

int main() {
  while (true) {
    int N, M;
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}