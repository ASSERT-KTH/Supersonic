#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

int N, M;
struct Info {
  std::string from, to;
  int rank;
  bool erased;
};
struct Data {
  std::string from, to, message;
};

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
    if (buf[0] == 'p') {
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
  // remaining code
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