#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int N, M;

struct Info {
  std::string from, to;
  int rank;
  bool erased;
};

struct Data {
  std::string from, to, message;
};

bool strCmp(const std::string& base, const std::string& comp) {
  return base == comp;
}

bool ambiguousCmp(const std::string& base, const std::string& comp) {
  for (int i = 0; i < base.size(); i++) {
    if (base[i] != comp[i]) {
      if (base[i] != '?')
        return false;
    }
  }
  return true;
}

void func() {
  int ok_index = 0, not_index = 0;
  std::vector<Info> OK(N), NOT(N);

  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }

  std::string buf, from, to;
  bool FLG;

  for (int i = 0; i < N; i++) {
    std::cin >> buf >> from >> to;

    if (buf == "p") {
      OK[ok_index].from = from;
      OK[ok_index].to = to;
      OK[ok_index].rank = i;
      ok_index++;
    } else {
      NOT[not_index].from = from;
      NOT[not_index].to = to;
      NOT[not_index].rank = i;
      not_index++;
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

  std::queue<Data> Q;

  for (int loop = 0; loop < M; loop++) {
    Data data;
    std::cin >> data.from >> data.to >> data.message;
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

  printf("%d\n", static_cast<int>(Q.size()));

  while (!Q.empty()) {
    printf("%s %s %s\n", Q.front().from.c_str(), Q.front().to.c_str(), Q.front().message.c_str());
    Q.pop();
  }
}

int main() {
  while (true) {
    std::cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}