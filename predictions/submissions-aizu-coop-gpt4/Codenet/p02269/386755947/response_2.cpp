#include <cstdio>
#include <unordered_set>
using namespace std;

char k[128];
unordered_set<int> dnaSequences;

int c(char str[12]) {
  int ans = str[0], i = 1;
  for (i; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
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
      dnaSequences.insert(c(str));
    else
      puts(dnaSequences.count(c(str)) ? "yes" : "no");
  }
  return 0;
}