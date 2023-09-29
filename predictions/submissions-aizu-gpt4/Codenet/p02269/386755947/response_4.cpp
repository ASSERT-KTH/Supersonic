#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> d;
char k[128];
string c(char str[12]) {
  string ans(1, str[0]);
  for (int i = 1; str[i] != '\0'; i++) {
    ans.push_back(k[str[i]]);
  }
  return ans;
}
int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  int n;
  scanf("%d", &n);
  char s[7], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");
  }
  return 0;
}