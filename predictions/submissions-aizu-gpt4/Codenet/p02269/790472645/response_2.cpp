#include <cstdio>
#include <unordered_map>
#include <string>
#define MOD1 1000000007;
#define MOD2 1000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  int n;
  unordered_map<string, bool> dic;
  char opstr[7];
  char str[13];
  scanf("%d", &n);
  while (n--) {
    scanf("%s %s", opstr, str);
    if (opstr[0] == 'i') {
      dic[str] = true;
    } else if (opstr[0] == 'f') {
      if (dic[str])
        puts("yes");
      else
        puts("no");
    }
  }
  return 0;
}