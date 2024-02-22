#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstdio>
using namespace std;
unordered_set<int> d;
unordered_map<string, int> cache;
char k[128];

int c(const char* str) {
  // Check the cache first
  auto it = cache.find(str);
  if(it != cache.end())
    return it->second;

  // Not in cache, compute it
  int ans = str[0], i = 1;
  for (i; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
  }

  // Store the result in cache
  cache[str] = ans;
  
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
      d.insert(c(str));
    else
      puts(d.count(c(str)) ? "yes" : "no");
  }
  return 0;
}