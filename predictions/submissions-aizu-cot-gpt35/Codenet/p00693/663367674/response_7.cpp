#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>

struct Info {
  std::string from, to;
  int rank;
  bool erased;
};

struct Data {
  std::string from, to, message;
};

bool ambiguousCmp(const std::string& base, const std::string& comp) {
  for (size_t i = 0; i < base.size(); i++) {
    if (base[i] != comp[i]) {
      if (base[i] != '?') {
        return false;
      }
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

  std::unordered_set<int> erasedOK, erasedNOT;

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || erasedOK.count(k) > 0)
        continue;
      if (NOT[i].from == OK[k].from && NOT[i].to == OK[k].to) {
        erasedOK.insert(k);
      }
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || erasedNOT.count(k) > 0)
        continue;
      if (OK[i].from == NOT[k].from && OK[i].to == NOT[k].to) {
        erasedNOT.insert(k);
      }
    }
  }

  std::deque<Data> Q;

  for (int loop = 0; loop < M; loop++) {
    Data data;
    std::cin >> data.from >> data.to >> data.message;

    bool FLG = false;

    for (int i = 0; i < N; i++) {
      if (erasedOK.count(i) > 0)
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
      if (erasedNOT.count(i) > 0)
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

  std::cout << Q.size() << std::endl;

  while (!Q.empty()) {
    std::cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << std::endl;
    Q.pop_front();
  }
}

int main() {
  while (true) {
    int N, M;
    std::cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}