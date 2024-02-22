#include <cstdio>
using namespace std;

int dic_op(char str[14]) {
  int j;
  long long f = 1;
  long long g = 0;
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
  static bool dic[90000000];
  char op;
  char str[13];
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %c %s", &op, str);
    if (op == 'i') {
      dic[dic_op(str)] = true;
    } else if (op == 'f') {
      if (dic[dic_op(str)])
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}