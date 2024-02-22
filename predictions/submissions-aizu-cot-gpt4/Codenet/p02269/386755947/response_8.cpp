#include <cstdio>
#include <bitset>
#include <unordered_map>
using namespace std;

namespace {
    bitset<33554432> d;
    unordered_map<char, int> k = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
}

int c(char str[12]) {
  int ans = str[0];
  for (int i = 1; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  char s[7], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d.set(c(str));
    else
      puts(d.test(c(str)) ? "yes" : "no");
  }
  return 0;
}