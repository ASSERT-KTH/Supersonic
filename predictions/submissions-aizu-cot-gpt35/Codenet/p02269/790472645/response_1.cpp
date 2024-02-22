#include <cstdio>
#include <unordered_map>

typedef unsigned long long ull;

ull pow(ull x, ull n) {
  ull res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}

ull dic_op(char str[14]) {
  int j;
  ull f = 1;
  ull g = 0;
  for (j = 0;; j++) {
    if (str[j] == 'A')
      g += f * 1;
    else if (str[j] == 'C')
      g += f * 2;
    else if (str[j] == 'G')
      g += f * 3;
    else if (str[j] == 'T')
      g += f * 4;
    else
      break;
    f *= 5;
  }
  return g;
}

int main() {
  int i, n;
  std::unordered_map<ull, bool> dic;
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[dic_op(str)] = true;
    } else if (opstr[0] == 'f') {
      if (dic.find(dic_op(str)) != dic.end())
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}