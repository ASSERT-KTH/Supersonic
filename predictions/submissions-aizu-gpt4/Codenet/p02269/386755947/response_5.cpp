#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, bool> d;
int main() {
  int n;
  scanf("%d", &n);
  char s[2], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    string str_cpp(str);
    if (s[0] == 'i')
      d[str_cpp] = true;
    else
      puts(d[str_cpp] ? "yes" : "no");
  }
  return 0;
}