#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char str[14]) {
  static const int lookup[256] = {
    /* 'A' */ 1, /* 'B' */ 0, /* 'C' */ 2, /* 'D' */ 0,
    /* 'E' */ 0, /* 'F' */ 0, /* 'G' */ 3, /* 'H' */ 0,
    /* 'I' */ 0, /* 'J' */ 0, /* 'K' */ 0, /* 'L' */ 0,
    /* 'M' */ 0, /* 'N' */ 0, /* 'O' */ 0, /* 'P' */ 0,
    /* 'Q' */ 0, /* 'R' */ 0, /* 'S' */ 0, /* 'T' */ 4,
    /* 'U' */ 0, /* 'V' */ 0, /* 'W' */ 0, /* 'X' */ 0,
    /* 'Y' */ 0, /* 'Z' */ 0, /* '[' */ 0, /* '\' */ 0,
    /* ']' */ 0, /* '^' */ 0, /* '_' */ 0, /* '`' */ 0,
    /* 'a' */ 0, /* 'b' */ 0, /* 'c' */ 0, /* 'd' */ 0,
    /* 'e' */ 0, /* 'f' */ 0, /* 'g' */ 0, /* 'h' */ 0,
    /* 'i' */ 0, /* 'j' */ 0, /* 'k' */ 0, /* 'l' */ 0,
    /* 'm' */ 0, /* 'n' */ 0, /* 'o' */ 0, /* 'p' */ 0,
    /* 'q' */ 0, /* 'r' */ 0, /* 's' */ 0, /* 't' */ 0,
    /* 'u' */ 0, /* 'v' */ 0, /* 'w' */ 0, /* 'x' */ 0,
    /* 'y' */ 0, /* 'z' */ 0, /* '{' */ 0, /* '|' */ 0,
    /* '}' */ 0, /* '~' */ 0
  };
  int j;
  ll f = 1;
  ll g = 0;
  for (j = 0;; j++) {
    if (str[j] == '\0')
      break;
    g += f * lookup[(unsigned char)str[j]];
    f *= 5;
  }
  return g;
}

int main() {
  int i, j, k, l;
  int n;
  ll ans = 0;
  bitset<90000000> dic;
  char opstr[7];
  char str[13];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> opstr >> str;
    if (opstr[0] == 'i') {
      dic.set(dic_op(str));
    } else if (opstr[0] == 'f') {
      if (dic[dic_op(str)])
        puts("yes");
      else
        puts("no");
      j++;
    }
  }
  return 0;
}