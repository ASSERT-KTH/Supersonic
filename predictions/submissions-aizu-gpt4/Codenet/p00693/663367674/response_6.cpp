#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

struct Info {
  string from, to;
  int rank;
  bool erased;
};

struct Data {
  string from, to, message;
};

void func() {
  int N, M;
  cin >> N >> M;
  vector<Info> OK(N), NOT(N);
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }
  string buf;
  int ok_index = 0, not_index = 0;
  for (int i = 0; i < N; i++) {
    cin >> buf >> OK[ok_index].from >> OK[ok_index].to;
    if (buf[0] == 'p') {
      OK[ok_index].rank = i;
      ok_index++;
    } else {
      NOT[not_index].from = OK[ok_index].from;
      NOT[not_index].to = OK[ok_index].to;
      NOT[not_index].rank = i;
      not_index++;
    }
  }
  for (int i = not_index - 1; i >= 0; i--)
    for (int k = ok_index - 1; k >= 0; k--)
      if (NOT[i].rank >= OK[k].rank && !OK[k].erased && NOT[i].from == OK[k].from && NOT[i].to == OK[k].to)
        OK[k].erased = true;

  for (int i = ok_index - 1; i >= 0; i--)
    for (int k = not_index - 1; k >= 0; k--)
      if (OK[i].rank >= NOT[k].rank && !NOT[k].erased && OK[i].from == NOT[k].from && OK[i].to == NOT[k].to)
        NOT[k].erased = true;

  queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    cin >> data.from >> data.to >> data.message;
    bool FLG = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased) continue;
      if (OK[i].from == data.from && OK[i].to == data.to) {
        FLG = true;
        break;
      }
    }
    if (!FLG) continue;
    FLG = true;
    for (int i = 0; i < not_index; i++) {
      if (NOT[i].erased) continue;
      if (NOT[i].from == data.from && NOT[i].to == data.to) {
        FLG = false;
        break;
      }
    }
    if (FLG) Q.push(data);
  }
  cout << Q.size() << "\n";
  while (!Q.empty()) {
    cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << "\n";
    Q.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}