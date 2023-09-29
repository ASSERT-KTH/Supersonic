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
const int MAX_N = 100005;
int N, M;
struct Info {
  char from[9], to[9];
  int rank;
  bool erased;
};
struct Data {
  char from[9], to[9], message[51];
};
char okFrom[MAX_N][9], okTo[MAX_N][9], notFrom[MAX_N][9], notTo[MAX_N][9];
int okRank[MAX_N], notRank[MAX_N];
bool okErased[MAX_N], notErased[MAX_N];
bool strCmp(char *base, char *comp) {
  int length1 = strlen(base);
  int length2 = strlen(comp);
  if (length1 != length2)
    return false;
  for (int i = 0; i < length1; i++) {
    if (base[i] != comp[i])
      return false;
  }
  return true;
}
bool ambiguousCmp(char *base, char *comp) {
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i]) {
      if (base[i] == '?') {
      } else {
        return false;
      }
    }
  }
  return true;
}
void func() {
  memset(okErased, false, sizeof(okErased));
  memset(notErased, false, sizeof(notErased));
  bool FLG;
  for (int i = 0; i < N; i++) {
    char buf[10], from[9], to[9];
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      strcpy(okFrom[i], from);
      strcpy(okTo[i], to);
      okRank[i] = i;
    } else {
      strcpy(notFrom[i], from);
      strcpy(notTo[i], to);
      notRank[i] = i;
    }
  }
  sort(okRank, okRank + N, [&](int a, int b) { return okRank[a] < okRank[b]; });
  sort(notRank, notRank + N, [&](int a, int b) { return notRank[a] < notRank[b]; });
  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (notRank[i] < okRank[k] || okErased[k] == true)
        continue;
      if (strCmp(notFrom[i], okFrom[k]) && strCmp(notTo[i], okTo[k])) {
        okErased[k] = true;
      }
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int k = N - 1; k >= 0; k--) {
      if (okRank[i] < notRank[k] || notErased[k] == true)
        continue;
      if (strCmp(okFrom[i], notFrom[k]) && strCmp(okTo[i], notTo[k])) {
        notErased[k] = true;
      }
    }
  }
  queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);
    FLG = false;
    for (int i = 0; i < N; i++) {
      if (okErased[i] == true)
        continue;
      if (ambiguousCmp(okFrom[i], data.from) && ambiguousCmp(okTo[i], data.to)) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    FLG = true;
    for (int i = 0; i < N; i++) {
      if (notErased[i] == true)
        continue;
      if (ambiguousCmp(notFrom[i], data.from) && ambiguousCmp(notTo[i], data.to)) {
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
    printf("%s %s %s\n", Q.front().from, Q.front().to, Q.front().message);
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