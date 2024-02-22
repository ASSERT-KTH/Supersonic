#include <cstdio>
#include <cmath>
#include <unordered_set>

typedef unsigned long long ull;

ull pow(ull x, ull n) {
  return std::pow(x, n);
}

int dic_op(char str[14]) {
  static int lookup[256];
  if (lookup['A'] == 0) {
    lookup['A'] = 1;
    lookup['C'] = 2;
    lookup['G'] = 3;
    lookup['T'] = 4;
  }

  int j;
  long long f = 1;
  long long g = 0;
  for (j = 0;; j++) {
    char ch = str[j];
    if (ch == '\0')
      break;
    g += f * lookup[ch];
    f *= 5;
  }
  return g;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::unordered_set<int> dic;
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic.insert(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic.count(dic_op(str)) > 0)
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}