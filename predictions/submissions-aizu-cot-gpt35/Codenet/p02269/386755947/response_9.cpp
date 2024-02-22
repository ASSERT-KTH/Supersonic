#include <cstdio>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int c(char str[]) {
  static unordered_map<char, int> k;
  if (k.empty()) {
    k['A'] = 0;
    k['C'] = 1;
    k['G'] = 2;
    k['T'] = 3;
  }
  
  int ans = str[0], i = 1;
  for (i; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  
  unordered_set<int> d;
  
  char* s = new char[7];
  char* str = new char[12];
  
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d.insert(c(str));
    else
      printf("%s\n", d.count(c(str)) ? "yes" : "no");
  }
  
  delete[] s;
  delete[] str;
  
  return 0;
}