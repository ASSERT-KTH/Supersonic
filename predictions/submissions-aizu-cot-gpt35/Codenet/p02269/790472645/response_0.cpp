#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

ull dic_op(char str[14]) {
  static const int lookup[256] = {
    /* ASCII values for 'A', 'C', 'G', 'T' */
    1, 0, 2, 3
  };

  ull g = 0;
  ull f = 1;
  for (int j = 0; str[j] != '\0'; j++) {
    g += f * lookup[str[j]];
    f *= 5;
  }
  return g;
}

int main() {
  int n;
  static char dic[90000000];
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = 1;
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)] == 1)
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}