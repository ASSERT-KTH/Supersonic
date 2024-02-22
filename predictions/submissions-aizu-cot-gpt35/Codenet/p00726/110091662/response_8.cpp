#include <iostream>
#include <vector>
using namespace std;

int N;

void dfs(const string& s, int start, int end, vector<char>& result) {
  int i = start;
  long long n = -1;
  
  while (i < end) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = i + 1;
      while (cnt) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      dfs(s, i + 1, j - 1, result);
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      for (int _ = 0; _ < n; _++) {
        result.push_back(s[i]);
        if (result.size() > N)
          return;
      }
      n = -1;
      i++;
    }
  }
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    vector<char> result;
    dfs(s, 0, s.size(), result);
    string r(result.begin(), result.end());
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}