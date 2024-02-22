#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <unordered_set>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
int N, M;
struct Data {
  char from[9], to[9], message[51];
};
void func() {
  int ok_index = 0, not_index = 0;
  vector<Data> OK, NOT;
  OK.reserve(N);
  NOT.reserve(N);
  char buf[10], from[9], to[9];
  for (int i = 0; i < N; i++) {
    scanf("%s %s %s", buf, from, to);
    if (buf[0] == 'p') {
      Data data;
      strcpy(data.from, from);
      strcpy(data.to, to);
      OK.push_back(data);
      ok_index++;
    } else {
      Data data;
      strcpy(data.from, from);
      strcpy(data.to, to);
      NOT.push_back(data);
      not_index++;
    }
  }
  unordered_set<int> erasedIndices;
  for (int i = not_index - 1; i >= 0; i--) {
    for (int k = ok_index - 1; k >= 0; k--) {
      if (NOT[i].rank < OK[k].rank || OK[k].erased == true)
        continue;
      if (strcmp(NOT[i].from, OK[k].from) == 0 &&
          strcmp(NOT[i].to, OK[k].to) == 0) {
        erasedIndices.insert(k);
      }
    }
  }
  for (int index : erasedIndices) {
    OK[index].erased = true;
  }
  vector<Data> Q;
  for (int loop = 0; loop < M; loop++) {
    Data data;
    scanf("%s %s %s", data.from, data.to, data.message);
    bool FLG = false;
    for (const Data& okData : OK) {
      if (okData.erased == true)
        continue;
      if (strcmp(okData.from, data.from) == 0 &&
          strcmp(okData.to, data.to) == 0) {
        FLG = true;
        break;
      }
    }
    if (!FLG)
      continue;
    FLG = true;
    for (const Data& notData : NOT) {
      if (notData.erased == true)
        continue;
      if (strcmp(notData.from, data.from) == 0 &&
          strcmp(notData.to, data.to) == 0) {
        FLG = false;
        break;
      }
    }
    if (FLG) {
      Q.push_back(data);
    }
  }
  printf("%zu\n", Q.size());
  for (const Data& data : Q) {
    printf("%s %s %s\n", data.from, data.to, data.message);
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