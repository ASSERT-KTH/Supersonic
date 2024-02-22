#include <algorithm>
#include <bits/stdc++.h>
#include <cfloat>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
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
  bool FLG = true;
  for (int i = 0; i < base.size(); i++) {
    if (base[i] != comp[i]) {
      if (base[i] != '?') {
        FLG = false;
        break;
      }
    }
  }
  return FLG;
}
void func() {
  int N, M;
  cin >> N >> M;
  if (N == 0 && M == 0)
    return;
    
  int ok_index = 0, not_index = 0;
  vector<Info> OK(N), NOT(N);
  string buf, from, to;
  bool FLG;
  
  // Use cin instead of scanf
  for (int i = 0; i < N; i++) {
    cin >> buf >> from >> to;
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
  // Rest of the code remains the same.
  
}
int main() {
  func();
  return 0;
}