#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Info {
  string from, to;
  int rank;
  bool erased;
};

struct Data {
  string from, to, message;
};

bool ambiguousCmp(const string& base, const string& comp) {
  for (size_t i = 0; i < base.size(); ++i) {
    if (base[i] != comp[i] && base[i] != '?') {
      return false;
    }
  }
  return true;
}

void func() {
  int N, M;
  cin >> N >> M;
  vector<Info> OK(N), NOT(N);
  for (auto& info : OK) {
    info.erased = false;
  }
  for (auto& info : NOT) {
    info.erased = false;
  }

  string buf, from, to;
  int ok_index = 0, not_index = 0;
  for (int i = 0; i < N; ++i) {
    cin >> buf >> from >> to;
    if (buf[0] == 'p') {
      OK[ok_index++] = {from, to, i, false};
    } else {
      NOT[not_index++] = {from, to, i, false};
    }
  }

  for (int i = not_index - 1; i >= 0; --i) {
    for (int k = ok_index - 1; k >= 0; --k) {
      if (NOT[i].rank > OK[k].rank && NOT[i].from == OK[k].from && NOT[i].to == OK[k].to) {
        OK[k].erased = true;
      }
      if (OK[k].rank > NOT[i].rank && OK[k].from == NOT[i].from && OK[k].to == NOT[i].to) {
        NOT[i].erased = true;
      }
    }
  }

  queue<Data> Q;
  for (int loop = 0; loop < M; ++loop) {
    Data data;
    cin >> data.from >> data.to >> data.message;
    bool FLG = false;
    for (const auto& ok : OK) {
      if (!ok.erased && ambiguousCmp(ok.from, data.from) && ambiguousCmp(ok.to, data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG) {
      continue;
    }
    for (const auto& notOk : NOT) {
      if (!notOk.erased && ambiguousCmp(notOk.from, data.from) && ambiguousCmp(notOk.to, data.to)) {
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
    const auto& front = Q.front();
    cout << front.from << " " << front.to << " " << front.message << "\n";
    Q.pop();
  }
}

int main() {
  int N, M;
  while (cin >> N >> M && !(N == 0 && M == 0)) {
    func();
  }
  return 0;
}