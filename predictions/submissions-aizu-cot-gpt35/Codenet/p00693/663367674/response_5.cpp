#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

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
  
  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased) {
        continue;
      }
      if (strCmp(NOT[i].from, OK[k].from) && strCmp(NOT[i].to, OK[k].to)) {
        OK[k].erased = true;
      }
    }
  }
  
  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased) {
        continue;
      }
      if (strCmp(OK[i].from, NOT[k].from) && strCmp(OK[i].to, NOT[k].to)) {
        NOT[k].erased = true;
      }
    }
  }
  
  std::queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", &data.from[0], &data.to[0], &data.message[0]);
    
    bool FLG = false;
    for (size_t i = 0; i < OK.size(); i++) {
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
    for (size_t i = 0; i < NOT.size(); i++) {
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
  
  printf("%d\n", Q.size());
  while (!Q.empty()) {
    printf("%s %s %s\n", Q.front().from.c_str(), Q.front().to.c_str(), Q.front().message.c_str());
    Q.pop();
  }
}

int main() {
  while (true) {
    func();
    int N, M;
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0) {
      break;
    }
  }
  
  return 0;
}