#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char str[14]) {
  int j;
  int f = 1;
  int g = 0;
  for (j = 0;; j++) {
    switch (str[j]) {
      case 'A':
        g |= f;
        break;
      case 'C':
        g |= (f << 1);
        break;
      case 'G':
        g |= (f << 2);
        break;
      case 'T':
        g |= (f << 3);
        break;
      default:
        return g;
    }
    f <<= 2;
  }
  return g;
}

int main() {
  int i, j, k, l;
  int n;
  long ans = 0;
  unordered_set<int> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.find(dic_op(str)) != dic.end())
        puts("yes");
      else
        puts("no");
      j++;
    }
  }
  return 0;
}