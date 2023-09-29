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
  char from[9], to[9];
  int rank;
  bool erased;
};
struct Data {
  char from[9], to[9], message[51];
};
bool strCmp(const char *base, const char *comp) {
  return strcmp(base,comp) == 0;
}
bool ambiguousCmp(const char *base, const char *comp) {
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
  vector<Info> OK(N), NOT(N);
  for (int i = 0; i < N; i++) {
    OK[i].erased = false;
    NOT[i].erased = false;
  }
  char buf[10], from[9], to[9];
  bool FLG;
  for (int i = 0; i < N; i++) {
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      strcpy(OK[i].from, from);
      strcpy(OK[i].to, to);
      OK[i].rank = i;
    } else {
      strcpy(NOT[i].from, from);
      strcpy(NOT[i].to, to);
      NOT[i].rank = i;
    }
  }
  sort(OK.begin(), OK.end(), [](const Info& a, const Info& b) { 
      return a.rank > b.rank; 
    });
  sort(NOT.begin(), NOT.end(), [](const Info& a, const Info& b) { 
      return a.rank > b.rank; 
    });
  for (int i = 0, j = 0; i < NOT.size(); i++) {
    while (j < OK.size() && OK[j].rank > NOT[i].rank) {
      j++;
    }
    if (j == OK.size()) break;
    if (strCmp(NOT[i].from, OK[j].from) && strCmp(NOT[i].to, OK[j].to)) {
      OK[j].erased = true;
    }
  }
  for (int i = 0, j = 0; i < OK.size(); i++) {
    while (j < NOT.size() && NOT[j].rank > OK[i].rank) {
      j++;
    }
    if (j == NOT.size()) break;
    if (strCmp(OK[i].from, NOT[j].from) && strCmp(OK[i].to, NOT[j].to)) {
      NOT[j].erased = true;
    }
  }
  queue<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);
    FLG = false;
    for (int i = 0; i < OK.size(); i++) {
      if (OK[i].erased == true)
        continue;
      if (ambiguousCmp(OK[i].from, data.from) == true &&
          ambiguousCmp(OK[i].to, data.to) == true) {
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
      if (ambiguousCmp(NOT[i].from, data.from) == true &&
          ambiguousCmp(NOT[i].to, data.to) == true) {
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