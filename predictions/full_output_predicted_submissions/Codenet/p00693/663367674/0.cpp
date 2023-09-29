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
bool strCmp(char *base, char *comp) {
  int length1 = 0, length2 = 0;
  for (int i = 0; base[i] != '\0'; i++)
    length1++;
  for (int i = 0; comp[i] != '\0'; i++)
    length2++;
  if (length1 != length2)
    return false;
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i])
      return false;
  }
  return true;
}
bool ambiguousCmp(char *base, char *comp) {
  bool FLG = true;
  for (int i = 0; base[i] != '\0'; i++) {
    if (base[i] != comp[i]) {
      if (base[i] == '?') {
      } else {
        FLG = false;
        break;
      }
    }
  }
  if (FLG)
    return true;
  else {
    return false;
  }
}
void strcpy(char *to, char *str) {
  for (int i = 0; str[i