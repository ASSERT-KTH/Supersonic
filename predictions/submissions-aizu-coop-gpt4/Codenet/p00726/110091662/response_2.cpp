#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

// Lookup table to check if a character is a digit
bool isDigit[256];
for (int i = '0'; i <= '9'; i++) isDigit[i] = true;

int N;
string dfs(const string& s, int& i) {
  stringstream r;
  long long n = -1;
  for (; i < s.size();) {
    if (isDigit[s[i]]) {
      n = (n < 0 ? 0 : n * 10) + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      n = (n < 0 ? 1 : n);
      int cnt = 1, j = i + 1;
      for (; cnt;) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      int k = i + 1;
      string r0 = dfs(s, k);
      for (int _ = 0; _ < n; _++) {
        r << r0;
        if (r.str().size() > N)
          return r.str();
      }
      n = -1;
      i = j;
    } else {
      n = (n < 0 ? 1 : n);
      r << string(n, s[i]);
      n = -1;
      i++;
    }
  }
  return r.str();
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    int i = 0;
    string r = dfs(s, i);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}