#include <cstdio>
#include <unordered_map>
using namespace std;

bool d[33554432];
unordered_map<char, int> k;
inline int c(char str[12]) {
  int ans = str[0];
  for (int i = 1; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
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