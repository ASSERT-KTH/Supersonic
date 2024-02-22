#include <algorithm>
#include <bits/stdc++.h>
#include <cfloat>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

using namespace std;

int N, M;

struct Info {
  string from;
  string to;
  int rank;
  bool erased;
};

struct Data {
  string from;
  string to;
  string message;
};

void func() {
  int ok_index = 0, not_index = 0;

  vector<Info> OK(N);
  vector<Info> NOT(N);

  char buf[10], from[9], to[9];
  bool FLG;

  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }

  for (int i = 0; i < N; i++) {
    scanf("%s %s %s", buf, from, to);

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

  for (int i = not_index - 1; i >= 0; i--) {
    for (int k = ok_index - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased == true)
        continue;
      if (NOT[i].from == OK[k].from && NOT[i].to == OK[k].to) {
        OK[k].erased = true;
      }
    }
  }

  for (int i = ok_index - 1; i >= 0; i--) {
    for (int k = not_index - 1; k >= 0; k--) {
      if (OK[i].rank < NOT[k].rank || NOT[k].erased == true)
        continue;
      if (OK[i].from == NOT[k].from && OK[i].to == NOT[k].to) {
        NOT[k].erased = true;
      }
    }
  }

  queue<Data> Q;

  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);

    FLG = false;
    for (int i = 0; i < ok_index; i++) {
      if (OK[i].erased == true)
        continue;
      if (OK[i].from.find('?') != string::npos &&
          OK[i].to.find('?') != string::npos) {
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
      if (NOT[i].from.find('?') != string::npos &&
          NOT[i].to.find('?') != string::npos) {
        FLG = false;
        break;
      }
    }

    if (FLG) {
      Q.push(data);
    }
  }

  printf("%lu\n", Q.size());

  while (!Q.empty()) {
    printf("%s %s %s\n", Q.front().from.c_str(), Q.front().to.c_str(),
           Q.front().message.c_str());
    Q.pop();
  }
}

int main() {
  while (true) {
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0)
      break;
    func();
  }
  return 0;
}