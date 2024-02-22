#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char* str, int len) {
  int j;
  ll f = 1;
  ll g = 0;
  for (j = 0; j < len; j++) {
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
  int i, j, k, l;
  int n;
  long ans = 0;
  char** dic;
  char* opstr;
  char* str;
  
  cin >> n;
  dic = new char*[n];
  opstr = new char[7];
  str = new char[13];
  
  for (i = 0; i < n; i++) {
    scanf("%s %s", opstr, str);
    int len = strlen(str);
    if (opstr[0] == 'i') {
      int index = dic_op(str, len);
      dic[index] = new char[1];
      dic[index][0] = 1;
    } else if (opstr[0] == 'f') {
      int index = dic_op(str, len);
      if (dic[index][0] == 1)
        puts("yes");
      else
        puts("no");
      j++;
    }
  }

  delete[] opstr;
  delete[] str;
  for (i = 0; i < n; i++) {
    delete[] dic[i];
  }
  delete[] dic;
  return 0;
}