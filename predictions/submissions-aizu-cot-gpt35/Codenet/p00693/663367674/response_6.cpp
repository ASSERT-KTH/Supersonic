#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Info {
  std::string from;
  std::string to;
  int rank;
  bool erased;
};

struct Data {
  std::string from;
  std::string to;
  std::string message;
};

bool ambiguousCmp(const std::string& base, const std::string& comp) {
  for (int i = 0; i < base.size(); i++) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}

void func() {
  int N, M;
  std::cin >> N >> M;

  std::vector<Info> OK(N), NOT(N);

  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }

  for (int i = 0; i < N; i++) {
    std::string buf, from, to;
    std::cin >> buf >> from >> to;
    if (buf == "p") {
      OK[i].from = from;
      OK[i].to = to;
      OK[i].rank = i;
    } else {
      NOT[i].from = from;
      NOT[i].to = to;
      NOT[i].rank = i;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased) {
        continue;
      }
      if (NOT[i].from == OK[k].from && NOT[i].to == OK[k].to) {
        OK[k].erased = true;
      }
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased) {
        continue;
      }
      if (OK[i].from == NOT[k].from && OK[i].to == NOT[k].to) {
        NOT[k].erased = true;
      }
    }
  }

  std::queue<Data> Q;

  for (int loop = 0; loop < M; loop++) {
    Data data;
    std::cin >> data.from >> data.to >> data.message;
    bool FLG = false;
    for (int i = 0; i < N; i++) {
      if (OK[i].erased) {
        continue;
      }
      if (ambiguousCmp(OK[i].from, data.from) && ambiguousCmp(OK[i].to, data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG) {
      continue;
    }
    FLG = true;
    for (int i = 0; i < N; i++) {
      if (NOT[i].erased) {
        continue;
      }
      if (ambiguousCmp(NOT[i].from, data.from) && ambiguousCmp(NOT[i].to, data.to)) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
      Q.push(data);
    }
  }

  std::cout << Q.size() << std::endl;
  while (!Q.empty()) {
    std::cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << std::endl;
    Q.pop();
  }
}

int main() {
  while (true) {
    int N, M;
    std::cin >> N >> M;
    if (N == 0 && M == 0) {
      break;
    }
    func();
  }
  return 0;
}